#include <cecxx/functions/multimodal/diff_powers.hpp>

#include <cmath>
#include <span>

namespace cecxx::functions::multimodal {
auto diff_powers(std::span<const double> input) -> double {
    auto output{0.0};
    for (auto i = 0u; i < input.size(); i++) {
        output += std::pow(std::fabs(input[i]), 2 + 4 * i / (input.size() - 1));
    }
    return std::pow(output, 0.5);
}
} // namespace cecxx::functions::multimodal
