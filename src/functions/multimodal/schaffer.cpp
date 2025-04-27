#include <cecxx/functions/multimodal/schaffer.hpp>

#include <cmath>
#include <print>

namespace cecxx::functions::multimodal {
auto schaffer(std::span<const double> input) -> double {
    auto nrow = input.size();
    auto tmp = double{};
    auto output = double{};
    for (auto i{0u}; i < nrow - 1; ++i) {
        tmp = sin(50.0 * pow(input[i], 0.2));
        output += pow(input[i], 0.5) + pow(input[i], 0.5) * tmp * tmp;
    }
    return output * output / (static_cast<double>(nrow) - 1) / (static_cast<double>(nrow) - 1);
}
} // namespace cecxx::functions::multimodal
