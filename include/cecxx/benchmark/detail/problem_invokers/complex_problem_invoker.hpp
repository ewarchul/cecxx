#pragma once

#include "cecxx/benchmark/detail/legacy/affine_transformation.hpp"
#include <vector>

#include <cecxx/benchmark/detail/context.hpp>

namespace cecxx::benchmark::detail {
struct complex_problem_params {
    std::vector<double> deltas{};
    std::vector<double> biases{};
    std::vector<affine_mask_t> masks{};
    std::unordered_map<std::size_t, std::pair<double, double>> scales{};
};

template <typename... F>
class complex_problem_invoker {
public:
    complex_problem_invoker(std::tuple<F...> compounds, complex_problem_params parameters)
        : compounds{compounds}, params{std::move(parameters)} {}

    auto operator()(std::span<const double> input, problem_context_view_t ctx) const -> double {

        constexpr auto compounds_num{std::tuple_size_v<decltype(compounds)>};
        constexpr auto fn_indxs = std::make_index_sequence<std::tuple_size_v<decltype(compounds)>>();

        auto partial_eval = invoke_impl(input, ctx, params.masks, fn_indxs);
        auto output = std::array<double, 1>{};
        cf_cal(input, output, ctx.shift, params.deltas, params.biases, partial_eval, compounds_num);

        return output[0];
    }

private:
    template <std::size_t... CompoundIndex>
    auto invoke_impl(std::span<const double> input, problem_context_view_t ctx, const std::vector<affine_mask_t> &masks,
                     std::index_sequence<CompoundIndex...>) const {
        auto partial_eval = std::array<double, std::tuple_size_v<decltype(compounds)>>{};
        const auto nrow = input.size();
        (
            [&](auto) {
                auto sub_ctx = problem_context_view_t{.shift = ctx.shift.subspan(nrow * CompoundIndex),
                                                      .rotate = ctx.rotate.subspan(nrow * nrow * CompoundIndex),
                                                      .shuffle = ctx.shuffle.subspan(nrow * CompoundIndex)};
                const auto mask = masks[CompoundIndex];
                auto comp_fn = std::get<CompoundIndex>(compounds);
                const auto [num, denom] = params.scales.at(CompoundIndex);
                partial_eval[CompoundIndex] = num * comp_fn(input, sub_ctx, mask) / denom;
            }(CompoundIndex),
            ...);
        return partial_eval;
    }

    std::tuple<F...> compounds{};
    complex_problem_params params{};
};
} // namespace cecxx::benchmark::detail
