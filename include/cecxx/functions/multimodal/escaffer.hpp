#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto escaffer(std::span<const f64> input) -> f64 {
  const auto nrow = input.size();
  auto output{0.0};
  f64 temp1{}, temp2{};
  for (auto i = 0u; i < nrow - 1; i++) {
    temp1 = std::sin(sqrt(input[i] * input[i] + input[i + 1] * input[i + 1]));
    temp1 = temp1 * temp1;
    temp2 = 1.0 + 0.001 * (input[i] * input[i] + input[i + 1] * input[i + 1]);
    output += 0.5 + (temp1 - 0.5) / (temp2 * temp2);
  }

  temp1 =
      std::sin(sqrt(input[nrow - 1] * input[nrow - 1] + input[0] * input[0]));
  temp1 = temp1 * temp1;
  temp2 =
      1.0 + 0.001 * (input[nrow - 1] * input[nrow - 1] + input[0] * input[0]);

  return output + 0.5 + (temp1 - 0.5) / (temp2 * temp2);
}
} // namespace cecxx::functions::multimodal
