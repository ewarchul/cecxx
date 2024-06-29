#pragma once

#include <span>

#include "cecxx/types.hpp"

namespace cecxx::functions::unimodal {

constexpr auto sphere(std::span<const f64> input) -> f64 {
  auto output{0.0};
  for (const auto &x : input) {
    output += x * x;
  }

  return output;
}
} // namespace cecxx::functions::unimodal
