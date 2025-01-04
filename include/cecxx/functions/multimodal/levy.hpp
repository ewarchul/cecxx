#pragma once

#include <cmath>
#include <span>

namespace cecxx::functions::multimodal {
auto levy(std::span<const double> input) -> double;
} // namespace cecxx::functions::multimodal
