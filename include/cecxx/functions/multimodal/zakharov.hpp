#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto zakharov(std::span<const f64> input) -> f64 {
  auto sum1{0.0};
  auto sum2{0.0};
  for (auto i = 0u; i < input.size(); i++) {
    sum1 = sum1 + std::pow(input[i], 2);
    sum2 = sum2 + 0.5 * (i + 1) * input[i];
  }
  return sum1 + std::pow(sum2, 2) + std::pow(sum2, 4);
}
}  // namespace cecxx::functions::multimodal
