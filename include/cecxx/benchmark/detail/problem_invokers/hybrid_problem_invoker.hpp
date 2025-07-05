#pragma once

#include <cmath>
#include <numeric>
#include <print>

#include <cecxx/benchmark/detail/context.hpp>
#include <cecxx/benchmark/detail/problem_invokers/affine_transformations.hpp>
#include <span>
#include <tuple>

namespace cecxx::benchmark::detail {

namespace {
auto print_vec2(auto &&xs) {
    for (auto &&[i, x] : xs | std::ranges::views::enumerate) {
        std::print("({}) {}, ", i, x);
    }
    std::println("");
}

} // namespace

auto calc_hybrid_chunks(std::ranges::range auto &&mix_ratios, const std::integral auto dim) {
    const auto fn_num = mix_ratios.size();
    auto chunk_size = std::vector<double>(fn_num);
    double acc{};
    for (auto i = 0u; i < fn_num - 1; ++i) {
        chunk_size[i] = std::ceil(mix_ratios[i] * static_cast<double>(dim));
        acc += chunk_size[i];
    }
    chunk_size[fn_num - 1] = static_cast<double>(dim) - acc;
    auto chunk_offset = std::vector<double>(fn_num);
    for (auto i = 1u; i < fn_num; i++) {
        chunk_offset[i] = chunk_offset[i - 1] + chunk_size[i - 1];
    }

    return std::make_pair(chunk_size, chunk_offset);
}

template <typename AF, typename... F>
class hybrid_problem_invoker {
public:
    constexpr hybrid_problem_invoker(AF affine_fns, std::tuple<F...> compounds, std::vector<double> compound_ratios)
        : trans_{affine_fns}, compounds{compounds}, compound_ratios{std::move(compound_ratios)} {}

    auto operator()(std::span<const double> input, problem_context_view_t ctx,
                    affine_mask_t mask = {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}

    ) const -> double {
        constexpr auto fn_indxs = std::make_index_sequence<std::tuple_size_v<decltype(compounds)>>();
        auto xs = apply_geom_fns(input, ctx, mask, trans_);
        const auto partial_eval = invoke_impl(xs, ctx, fn_indxs);
        return std::accumulate(partial_eval.begin(), partial_eval.end(), 0.0, std::plus{});
    }

private:
    template <std::size_t... CompoundIndices>
    auto invoke_impl(std::span<const double> input, problem_context_view_t ctx,
                     std::index_sequence<CompoundIndices...>) const {
        const auto [sizes, offsets] = calc_hybrid_chunks(compound_ratios, input.size());
        auto partial_eval = std::array<double, std::tuple_size_v<decltype(compounds)>>{};
        (
            [&](auto) {
                auto comp_fn = std::get<CompoundIndices>(compounds);
                const auto partial_input = input.subspan(static_cast<unsigned int>(offsets[CompoundIndices]),
                                                         static_cast<unsigned int>(sizes[CompoundIndices]));
                partial_eval[CompoundIndices] = comp_fn(
                    partial_input, ctx, affine_mask_t{.rot = do_affine_trans::no, .shift = do_affine_trans::no});
            }(CompoundIndices),
            ...);

        return partial_eval;
    }
    AF trans_{};
    std::tuple<F...> compounds{};
    std::vector<double> compound_ratios{};
};
} // namespace cecxx::benchmark::detail
