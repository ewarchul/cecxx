#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
inline auto discus(std::span<const f64> input) -> f64 {
  auto output = std::pow(10.0, 6.0) * input[0] * input[0];
  for (auto i = 1u; i < input.size(); i++) {
    output += input[i] * input[i];
  }
  return output;
}
} // namespace cecxx::functions::multimodal
