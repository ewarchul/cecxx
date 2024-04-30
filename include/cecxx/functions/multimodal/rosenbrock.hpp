#pragma once

#include <span>

namespace cecxx::functions::multimodal {
constexpr auto rosenbrock(std::span<const double> input) -> double {
  auto output{0.0};
  double tmp1{};
  for (auto i = 0u; i < input.size() - 1; ++i) {
    tmp1 = (input[i] + 1.0) * (input[i] + 1.0) - (input[i + 1] + 1.0);
    output += 100.0 * tmp1 * tmp1 + input[i] * input[i];
  }

  return output;
}
}  // namespace cecxx::functions::multimodal
