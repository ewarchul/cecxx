#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto hgbat(std::span<const f64> input) -> f64 {
  const auto nrow = input.size();
  f64 r2{}, sum_z{};
  constexpr auto alpha = 1.0 / 4.0;
  for (auto i = 0u; i < nrow; i++) {
    r2 += (input[i] - 1.0) * (input[i] - 1.0);
    sum_z += (input[i] - 1.0);
  }
  return std::pow(std::fabs(std::pow(r2, 2.0) - std::pow(sum_z, 2.0)),
                  2 * alpha) +
         (0.5 * r2 + sum_z) / static_cast<f64>(nrow) + 0.5;
}
} // namespace cecxx::functions::multimodal
