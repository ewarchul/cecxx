#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto step_rastrigin(std::span<const f64> input) -> f64 {
  auto output{0.0};
  for (const auto &x : input) {
    output += (x * x - 10.0 * std::cos(2.0 * M_PI * x) + 10.0);
  }

  return output;
}
} // namespace cecxx::functions::multimodal
