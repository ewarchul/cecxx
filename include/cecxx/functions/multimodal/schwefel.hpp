#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::multimodal {
constexpr auto schwefel(std::span<const f64> input) -> f64 {
  const auto nrow = input.size();
  auto tmp{0.0};
  auto output{0.0};
  constexpr auto shift = 4.209687462275036e+002;
  for (auto i = 0u; i < nrow; i++) {
    if ((input[i] + shift) > 500) {
      output -= (500.0 - std::fmod((input[i] + shift), 500)) *
                std::sin(std::pow(500.0 - std::fmod((input[i] + shift), 500), 0.5));
      tmp = ((input[i] + shift) - 500.0) / 100;
      output += tmp * tmp / static_cast<f64>(nrow);
    } else if ((input[i] + shift) < -500) {
      output -= (-500.0 + std::fmod(std::fabs((input[i]) + shift), 500)) *
                std::sin(std::pow(500.0 - std::fmod(std::fabs((input[i] + shift)), 500), 0.5));
      tmp = ((input[i] + shift) + 500.0) / 100;
      output += tmp * tmp / static_cast<f64>(nrow);
    } else {
      output -= (input[i] + shift) * std::sin(std::pow(std::fabs((input[i] + shift)), 0.5));
    }
  }
  output += 4.189828872724338e+002 * static_cast<f64>(nrow);
  return output;
}
}  // namespace cecxx::functions::multimodal
