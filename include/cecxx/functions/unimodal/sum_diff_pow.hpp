#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::unimodal {
constexpr auto sum_diff_pow(std::span<const f64> input) -> f64 {
  auto output{0.0};
  for (auto i = 0u; i < input.size(); i++) {
    output += std::pow(std::fabs(input[i]), i + 1);
  }
  return output;
}
} // namespace cecxx::functions::unimodal
