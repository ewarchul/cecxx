#pragma once

#include "cecxx/benchmark/types.hpp"
#include <cecxx/benchmark/detail/func_types.hpp>
#include <cecxx/benchmark/detail/geom.hpp>
#include <optional>

namespace cecxx::benchmark::detail {

template <typename EvaluationFunction>
struct basic_problem_invoker {
    constexpr basic_problem_invoker(EvaluationFunction fn, double scale, affine_mask_t mask,
                                    double asymmetric_trans_coeff = 1.0)
        : fn{std::move(fn)}, scale_mul{scale}, mask_{mask}, asymmetric_trans_coeff_{asymmetric_trans_coeff} {}

    auto operator()(std::span<const double> input, problem_context_view_t ctx, std::optional<affine_mask_t> mask = {},
                    const std::vector<double> &acc = {}) const -> double {
        const auto used_mask = mask.has_value() ? mask.value() : mask_;
        if constexpr (std::is_same_v<EvaluationFunction, stateless_eval_func>) {
            auto [_, z] = apply_geom_transformations(input, ctx, used_mask, scale_mul, asymmetric_trans_coeff_);
            return fn(z);
        } else if constexpr (std::is_same_v<EvaluationFunction, local_statefull_eval_func>) {
            return fn(input, ctx, used_mask);
        } else if constexpr (std::is_same_v<EvaluationFunction, nonlocal_statefull_eval_func>) {
            return fn(input, ctx, used_mask, acc);
        }

        throw std::runtime_error{"Failed to identify type of function"};
    }

    std::decay_t<EvaluationFunction> fn{};
    double scale_mul{};
    affine_mask_t mask_{};
    double asymmetric_trans_coeff_{};
};

} // namespace cecxx::benchmark::detail
