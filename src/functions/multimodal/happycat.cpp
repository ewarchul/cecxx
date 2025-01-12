#include <cecxx/functions/multimodal/happycat.hpp>

#include <cmath>
#include <span>

namespace cecxx::functions::multimodal {
auto happycat(std::span<const double> input) -> double {
    const auto nrow = input.size();
    double r2{}, sum_z{};
    constexpr auto alpha = 1.0 / 8.0;
    for (auto i = 0u; i < nrow; i++) {
        r2 += (input[i] - 1.0) * (input[i] - 1.0);
        sum_z += (input[i] - 1.0);
    }
    return std::pow(std::fabs(r2 - static_cast<double>(nrow)), 2 * alpha)
           + (0.5 * r2 + sum_z) / static_cast<double>(nrow) + 0.5;
}
} // namespace cecxx::functions::multimodal
