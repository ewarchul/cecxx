#pragma once

#include <cmath>
#include <span>

namespace cecxx::functions::unimodal {
auto sum_diff_pow(std::span<const double> input) -> double;
} // namespace cecxx::functions::unimodal
