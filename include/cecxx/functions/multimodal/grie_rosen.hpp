#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto grie_rosen(std::span<const f64> input) -> f64 {
  const auto nrow = input.size();
  f64 temp{}, tmp1{};
  auto output{0.0};
  for (auto i = 0u; i < nrow - 1; i++) {
    tmp1 = (input[i] + 1.0) * (input[i] + 1.0) - (input[i + 1] + 1.0);
    temp = 100.0 * tmp1 * tmp1 + input[i] * input[i];
    output += (temp * temp) / 4000.0 - std::cos(temp) + 1.0;
  }
  tmp1 = (input[nrow - 1] + 1.0) * (input[nrow - 1] + 1.0) - (input[0] + 1.0);
  temp = 100.0 * tmp1 * tmp1 + input[nrow - 1] * input[nrow - 1];
  output += (temp * temp) / 4000.0 - std::cos(temp) + 1.0;

  return output;
}
}  // namespace cecxx::functions::multimodal
