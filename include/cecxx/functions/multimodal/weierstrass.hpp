#pragma once

#include <cmath>
#include <span>

namespace cecxx::functions::multimodal {
constexpr auto weierstrass(std::span<const double> input) -> double {
  const auto nrow = input.size();
  constexpr auto a{0.5};
  constexpr auto b{3.0};
  constexpr auto k_max{20};

  auto output{0.0};
  double sum{};
  double sum2{};
  for (auto i = 0u; i < nrow; i++) {
    sum = 0.0;
    sum2 = 0.0;
    for (auto j = 0u; j <= k_max; j++) {
      sum += std::pow(a, j) * std::cos(2.0 * M_PI * std::pow(b, j) * (input[i] + 0.5));
      sum2 += std::pow(a, j) * std::cos(2.0 * M_PI * std::pow(b, j) * 0.5);
    }
    output += sum;
  }

  return output - static_cast<double>(nrow) * sum2;
}
}  // namespace cecxx::functions::multimodal
