#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

#define E 2.7182818284590452353602874713526625

namespace cecxx::functions::multimodal {
constexpr auto ackley(std::span<const f64> input) -> f64 {
  const auto nrow = input.size();
  f64 sum1{};
  f64 sum2{};
  for (auto i = 0u; i < nrow; ++i) {
    sum1 += input[i] * input[i];
    sum2 += std::cos(2.0 * M_PI * input[i]);
  }
  sum1 = -0.2 * std::sqrt(sum1 / static_cast<f64>(nrow));
  sum2 /= static_cast<f64>(nrow);
  return E - 20.0 * std::exp(sum1) - std::exp(sum2) + 20.0;
}
}  // namespace cecxx::functions::multimodal
