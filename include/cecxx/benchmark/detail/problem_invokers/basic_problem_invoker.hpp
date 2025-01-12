#pragma once

#include <cecxx/benchmark/detail/func_types.hpp>
#include <cecxx/benchmark/detail/geom.hpp>

namespace cecxx::benchmark::detail {

template <typename EvaluationFunction>
struct basic_problem_invoker {
    constexpr basic_problem_invoker(EvaluationFunction fn, double scale = 1.0) : scale_mul{scale}, fn{std::move(fn)} {}

    auto operator()(std::span<const double> input, problem_context_view_t ctx,
                    affine_mask_t mask = {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes, .rate = 1.0},
                    const std::vector<double> &acc = {}) const -> double {
        if constexpr (std::is_same_v<EvaluationFunction, stateless_eval_func>) {
            auto [_, z] = apply_geom_transformations(input, ctx, mask, scale_mul);
            return fn(z);
        } else if constexpr (std::is_same_v<EvaluationFunction, local_statefull_eval_func>) {
            return fn(input, ctx, mask);
        } else if constexpr (std::is_same_v<EvaluationFunction, nonlocal_statefull_eval_func>) {
            return fn(input, ctx, mask, acc);
        }

        throw std::runtime_error{"Failed to identify type of function"};
    }

    double scale_mul{};
    std::decay_t<EvaluationFunction> fn{};
};

} // namespace cecxx::benchmark::detail
