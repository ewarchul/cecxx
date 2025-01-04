#pragma once

#include <cmath>
#include <span>

namespace cecxx::functions::unimodal {
constexpr auto sum_diff_pow(std::span<const double> input) -> double {
    auto output{0.0};
    for (auto i = 0u; i < input.size(); i++) {
        output += std::pow(std::fabs(input[i]), i + 1);
    }
    return output;
}
} // namespace cecxx::functions::unimodal
