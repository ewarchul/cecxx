#pragma once

#include <cmath>
#include <span>

namespace cecxx::functions::unimodal {
constexpr auto bent_cigar(std::span<const double> input) -> double;
} // namespace cecxx::functions::unimodal
