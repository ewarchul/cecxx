#pragma once

#include <cmath>
#include <span>

namespace cecxx::functions::unimodal {
constexpr auto bent_cigar(std::span<const double> input) -> double {
  auto output{input[0] * input[0]};
  for (auto i = 1u; i < input.size(); ++i) {
    output += std::pow(10.0, 6.0) * input[i] * input[i];
  }

  return output;
}
}  // namespace cecxx::functions::unimodal
