#pragma once

#include <cmath>
#include <ostream>
#include <print>
#include <span>
#include <utility>
#include <vector>

#include <cecxx/benchmark/detail/context.hpp>
#include <cecxx/benchmark/detail/legacy/affine_transformation.hpp>

namespace cecxx::benchmark::detail {

inline auto apply_geom_transformations(std::span<const double> input, problem_context_view_t ctx, affine_mask_t mask,
                                       double scale_mul = 1.0, double asymm_scale_coeff = 1.0) {
    const auto nrow = input.size();
    std::ignore = asymm_scale_coeff;

    auto y_out = std::vector<double>(nrow);
    auto z_out = std::vector<double>(nrow);
    sr_func(input, z_out, ctx.shift, ctx.rotate, scale_mul, mask.shift, mask.rot, y_out);
    if (std::to_underlying(mask.orthosymmetric_trans)) {
        oszfunc(z_out, y_out);
    }

    if (std::to_underlying(mask.asymmetric_trans)) {
        asyfunc(y_out, z_out, asymm_scale_coeff);
        if (std::to_underlying(mask.rot)) {
            rotatefunc(z_out, y_out, ctx.rotate.subspan(nrow * nrow));
        }
        for (auto i{0u}; i < nrow; ++i) {
            y_out[i] *= std::pow(10.0, 1.0 * i / static_cast<double>(nrow - 1) / 2);
        }
        if (std::to_underlying(mask.rot)) {
            rotatefunc(y_out, z_out, ctx.rotate.subspan(nrow * nrow));
        }
    }

    // for (auto i = 0; i < nrow; ++i) {
    //     std::println("y[{}] -> {}", i, y_out[i]);
    // }
    // for (auto i = 0; i < nrow; ++i) {
    //     std::println("z[{}] -> {}", i, z_out[i]);
    // }

    return std::make_pair(y_out, z_out);
}
} // namespace cecxx::benchmark::detail
