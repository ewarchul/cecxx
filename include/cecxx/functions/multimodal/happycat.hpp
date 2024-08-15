#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto happycat(std::span<const f64> input) -> f64 {
  const auto nrow = input.size();
  f64 r2{}, sum_z{};
  constexpr auto alpha = 1.0 / 8.0;
  for (auto i = 0u; i < nrow; i++) {
    r2 += (input[i] - 1.0) * (input[i] - 1.0);
    sum_z += (input[i] - 1.0);
  }
  return std::pow(std::fabs(r2 - static_cast<f64>(nrow)), 2 * alpha) +
         (0.5 * r2 + sum_z) / static_cast<f64>(nrow) + 0.5;
}
}  // namespace cecxx::functions::multimodal
