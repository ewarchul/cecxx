#pragma once

#include <span>

namespace cecxx::functions::multimodal {
constexpr auto rosenbrock(std::span<const double> input) -> double;
} // namespace cecxx::functions::multimodal
