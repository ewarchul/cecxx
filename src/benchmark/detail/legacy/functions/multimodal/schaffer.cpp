/*
 *  Besides C++ features like automatic type deduction and span usage instead of C arrays,
 *  the core of this code is taken from the legacy implementation and shall be rewritten.
 */

#include <cecxx/benchmark/detail/legacy/affine_transformation.hpp>
#include <cecxx/benchmark/detail/legacy/functions/multimodal/schaffer.hpp>

namespace cecxx::functions::multimodal::legacy {
auto schaffer(std::span<const double> input, benchmark::detail::problem_context_view_t ctx,
              benchmark::affine_mask_t mask, std::vector<double> acc) -> double {
    const auto nrow = input.size();
    std::vector<double> ys{};
    if (acc.empty()) {
        ys.resize(nrow);
    } else {
        ys = acc;
    }
    auto z = std::vector<double>(nrow);

    auto output{0.0};
    benchmark::detail::sr_func(input, z, ctx.shift, ctx.rotate, 1.0, mask.shift, mask.rot, ys);
    double tmp{};
    for (auto i = 0u; i < nrow - 1; ++i) {
        z[i] = std::pow(ys[i] * ys[i] + ys[i + 1] * ys[i + 1], 0.5);
        tmp = std::sin(50.0 * std::pow(z[i], 0.2));
        output += std::pow(z[i], 0.5) + std::pow(z[i], 0.5) * tmp * tmp;
    }

    return output * output / (static_cast<double>(nrow) - 1) / (static_cast<double>(nrow) - 1);
}
} // namespace cecxx::functions::multimodal::legacy
