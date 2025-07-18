#include <cecxx/functions/multimodal/grie_rosen.hpp>

#include <cmath>
#include <span>

namespace cecxx::functions::multimodal {
auto grie_rosen(std::span<const double> input) -> double {
    const auto nrow = input.size();
    double temp{}, tmp1{};
    auto output{0.0};
    for (auto i = 0u; i < nrow - 1; i++) {
        tmp1 = (input[i]) * (input[i]) - (input[i + 1]);
        temp = 100.0 * tmp1 * tmp1 + (input[i] - 1.0) * (input[i] - 1.0);
        output += (temp * temp) / 4000.0 - std::cos(temp) + 1.0;
    }
    tmp1 = (input[nrow - 1]) * (input[nrow - 1]) - (input[0]);
    temp = 100.0 * tmp1 * tmp1 + (input[nrow - 1] - 1.0) * (input[nrow - 1] - 1.0);
    output += (temp * temp) / 4000.0 - std::cos(temp) + 1.0;

    return output;
}
} // namespace cecxx::functions::multimodal
