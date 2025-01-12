#pragma once

#include <cmath>
#include <span>

namespace cecxx::functions::multimodal {
auto ackley(std::span<const double> input) -> double;
} // namespace cecxx::functions::multimodal
