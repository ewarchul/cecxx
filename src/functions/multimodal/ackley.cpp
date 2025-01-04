#pragma once

#include <cmath>
#include <span>

inline constexpr auto E{2.7182818284590452353602874713526625};

namespace cecxx::functions::multimodal {
constexpr auto ackley(std::span<const double> input) -> double {
    const auto nrow = input.size();
    double sum1{};
    double sum2{};
    for (auto i = 0u; i < nrow; ++i) {
        sum1 += input[i] * input[i];
        sum2 += std::cos(2.0 * M_PI * input[i]);
    }
    sum1 = -0.2 * std::sqrt(sum1 / static_cast<double>(nrow));
    sum2 /= static_cast<double>(nrow);
    return E - 20.0 * std::exp(sum1) - std::exp(sum2) + 20.0;
}
} // namespace cecxx::functions::multimodal
