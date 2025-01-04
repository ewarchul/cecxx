#pragma once

#include <cmath>
#include <span>

namespace cecxx::functions::multimodal {
constexpr auto step_rastrigin(std::span<const double> input) -> double;
} // namespace cecxx::functions::multimodal
