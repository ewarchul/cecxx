#pragma once

#include <span>

namespace cecxx::functions::multimodal {
auto rosenbrock(std::span<const double> input) -> double;
} // namespace cecxx::functions::multimodal
