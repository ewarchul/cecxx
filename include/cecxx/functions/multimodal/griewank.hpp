#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto griewank(std::span<const f64> input) -> f64 {
  auto sum = 0.0;
  auto tmp = 1.0;
  for (auto i = 0u; i < input.size(); i++) {
    sum += input[i] * input[i];
    tmp *= std::cos(input[i] / sqrt(1.0 + i));
  }
  return 1.0 + sum / 4000.0 - tmp;
}
}  // namespace cecxx::functions::multimodal
