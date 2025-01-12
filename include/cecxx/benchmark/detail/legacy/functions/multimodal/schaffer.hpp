#pragma once

#include <cmath>
#include <vector>

#include <cecxx/benchmark/detail/context.hpp>

namespace cecxx::functions::multimodal::legacy {
auto schaffer(std::span<const double> input, benchmark::detail::problem_context_view_t ctx,
              benchmark::affine_mask_t mask, std::vector<double> acc = {}) -> double;

} // namespace cecxx::functions::multimodal::legacy
