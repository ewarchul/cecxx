#pragma once

#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto rosenbrock(std::span<const f64> input) -> f64 {
  auto output{0.0};
  f64 tmp1{};
  for (auto i = 0u; i < input.size() - 1; ++i) {
    tmp1 = (input[i] + 1.0) * (input[i] + 1.0) - (input[i + 1] + 1.0);
    output += 100.0 * tmp1 * tmp1 + input[i] * input[i];
  }

  return output;
}
} // namespace cecxx::functions::multimodal
