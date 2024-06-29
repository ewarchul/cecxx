#pragma once

#include <cmath>
#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::unimodal {

constexpr auto ellips(std::span<const f64> input) -> f64 {
  auto output{0.0};
  for (auto i = 0u; i < input.size(); ++i) {
    output += std::pow(10.0, 6.0 * i / (static_cast<f64>(input.size()) - 1)) *
              input[i] * input[i];
  }

  return output;
}
} // namespace cecxx::functions::unimodal
