#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto katsuura(std::span<const f64> input) -> f64 {
  const auto nrow = input.size();
  auto output{1.0};
  f64 temp{}, tmp1{}, tmp2{}, tmp3{};
  tmp3 = std::pow(1.0 * static_cast<f64>(nrow), 1.2);
  for (auto i = 0u; i < nrow; i++) {
    temp = 0.0;
    for (auto j = 1u; j <= 32; j++) {
      tmp1 = std::pow(2.0, j);
      tmp2 = tmp1 * input[i];
      temp += std::fabs(tmp2 - std::floor(tmp2 + 0.5)) / tmp1;
    }
    output *= std::pow(1.0 + (i + 1) * temp, 10.0 / tmp3);
  }
  tmp1 = 10.0 / static_cast<f64>(nrow) / static_cast<f64>(nrow);

  return output * tmp1 - tmp1;
}
}  // namespace cecxx::functions::multimodal
