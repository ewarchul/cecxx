#pragma once

#include <span>
#include <vector>

#include "cecxx/benchmark/detail/context.hpp"
#include "cecxx/benchmark/detail/legacy/affine_transformation.hpp"

namespace cecxx::benchmark::detail {

inline auto apply_geom_transformations(std::span<const double> input, problem_context_view ctx, affine_mask_t mask,
                                       double scale_mul = 1.0) {
    const auto nrow = input.size();
    auto y_out = std::vector<double>(nrow);
    auto z_out = std::vector<double>(nrow);
    sr_func(input, z_out, ctx.shift, ctx.rotate, scale_mul, mask.shift, mask.rot, y_out);
    return std::make_pair(y_out, z_out);
}
} // namespace cecxx::benchmark::detail
