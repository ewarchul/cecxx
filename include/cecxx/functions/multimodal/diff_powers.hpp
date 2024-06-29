#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto diff_powers(std::span<const f64> input) -> f64 {
  auto output{0.0};
  for (auto i = 0u; i < input.size(); i++) {
    output += std::pow(std::fabs(input[i]), 2 + 4 * i / (input.size() - 1));
  }
  return std::pow(output, 0.5);
}
}  // namespace cecxx::functions::multimodal
