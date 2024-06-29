#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto weierstrass(std::span<const f64> input) -> f64 {
  const auto nrow = input.size();
  constexpr auto a{0.5};
  constexpr auto b{3.0};
  constexpr auto k_max{20};

  auto output{0.0};
  f64 sum{};
  f64 sum2{};
  for (auto i = 0u; i < nrow; i++) {
    sum = 0.0;
    sum2 = 0.0;
    for (auto j = 0u; j <= k_max; j++) {
      sum += std::pow(a, j) *
             std::cos(2.0 * M_PI * std::pow(b, j) * (input[i] + 0.5));
      sum2 += std::pow(a, j) * std::cos(2.0 * M_PI * std::pow(b, j) * 0.5);
    }
    output += sum;
  }

  return output - static_cast<f64>(nrow) * sum2;
}
} // namespace cecxx::functions::multimodal
