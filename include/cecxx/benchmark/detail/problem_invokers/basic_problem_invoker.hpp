#pragma once

#include "cecxx/benchmark/types.hpp"
#include <cecxx/benchmark/detail/func_types.hpp>
#include <optional>
#include <print>
#include <ranges>
#include <utility>

#include <cecxx/benchmark/detail/problem_invokers/affine_transformations.hpp>

namespace cecxx::benchmark::detail {
template <typename T, T... S, typename F>
constexpr void for_sequence(std::integer_sequence<T, S...>, F &&f) {
    (void(f(std::integral_constant<T, S>{})), ...);
}

template <typename EvaluationFunction, typename... AffineTransformation>
struct basic_problem_invoker {
    constexpr basic_problem_invoker(EvaluationFunction fn, affine_mask_t mask,
                                    std::tuple<AffineTransformation...> affine_fns)
        : fn{std::move(fn)}, mask_{mask}, trans_{affine_fns} {}

    auto operator()(std::span<const double> input, problem_context_view_t ctx,
                    std::optional<affine_mask_t> mask = {}) const -> double {
        const auto used_mask = mask.has_value() ? mask.value() : mask_;
        if constexpr (std::is_same_v<EvaluationFunction, contextless_eval_func>) {

            return fn(apply_geom_fns(input, ctx, used_mask, trans_));
        } else if constexpr (std::is_same_v<EvaluationFunction, contextful_eval_func>) {
            return fn(input, ctx, used_mask);
        }

        throw std::runtime_error{"Failed to identify type of function"};
    }

    std::decay_t<EvaluationFunction> fn{};
    affine_mask_t mask_{};
    std::tuple<AffineTransformation...> trans_{};
};

} // namespace cecxx::benchmark::detail
