#pragma once

#include <cmath>

#include "cecxx/benchmark/detail/context.hpp"

namespace cecxx::functions::multimodal::legacy {

auto bi_rastrigin(std::span<const double> input, benchmark::detail::problem_context_view_t ctx,
                  benchmark::affine_mask_t mask) -> double;

} // namespace cecxx::functions::multimodal::legacy
