#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::unimodal {
constexpr auto bent_cigar(std::span<const f64> input) -> f64 {
  auto output{input[0] * input[0]};
  for (auto i = 1u; i < input.size(); ++i) {
    output += std::pow(10.0, 6.0) * input[i] * input[i];
  }

  return output;
}
} // namespace cecxx::functions::unimodal
