#pragma once

#include <cmath>
#include <span>
#include <vector>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto levy(std::span<const f64> input) -> f64 {
  const auto nrow = input.size();
  auto w = std::vector<f64>(nrow);
  for (auto i = 0u; i < nrow; i++) {
    w[i] = 1.0 + (input[i] - 1.0) / 4.0;
  }
  f64 term1 = std::pow((std::sin(M_PI * w[0])), 2);
  f64 term2 =
      std::pow((w[nrow - 1] - 1), 2) * (1 + std::pow((std::sin(2 * M_PI * w[nrow - 1])), 2));
  f64 sum = 0.0;
  for (auto i = 0u; i < nrow - 1; i++) {
    sum += std::pow((w[i] - 1), 2) * (1 + 10 * std::pow((std::sin(M_PI * w[i] + 1)), 2));
  }
  return term1 + sum + term2;
}
}  // namespace cecxx::functions::multimodal
