#include <cecxx/functions/multimodal/step_rastrigin.hpp>

#include <cmath>
#include <span>

namespace cecxx::functions::multimodal {
auto step_rastrigin(std::span<const double> input) -> double {
    auto output{0.0};
    for (const auto &x : input) {
        output += (x * x - 10.0 * std::cos(2.0 * M_PI * x) + 10.0);
    }

    return output;
}
} // namespace cecxx::functions::multimodal
