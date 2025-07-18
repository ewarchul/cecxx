#include <cecxx/functions/multimodal/schwefel.hpp>

#include <cmath>
#include <span>

namespace cecxx::functions::multimodal {
auto schwefel(std::span<const double> input) -> double {
    const auto nrow = input.size();
    auto tmp{0.0};
    auto output{0.0};
    for (auto i = 0u; i < nrow; i++) {
        if ((input[i]) > 500) {
            output
                -= (500.0 - std::fmod((input[i]), 500)) * std::sin(std::pow(500.0 - std::fmod((input[i]), 500), 0.5));
            tmp = ((input[i]) - 500.0) / 100;
            output += tmp * tmp / static_cast<double>(nrow);
        } else if ((input[i]) < -500) {
            output -= (-500.0 + std::fmod(std::fabs((input[i])), 500))
                      * std::sin(std::pow(500.0 - std::fmod(std::fabs((input[i])), 500), 0.5));
            tmp = ((input[i]) + 500.0) / 100;
            output += tmp * tmp / static_cast<double>(nrow);
        } else {
            output -= (input[i]) * std::sin(std::pow(std::fabs((input[i])), 0.5));
        }
    }
    output += 4.189828872724338e+002 * static_cast<double>(nrow);
    return output;
}
} // namespace cecxx::functions::multimodal
