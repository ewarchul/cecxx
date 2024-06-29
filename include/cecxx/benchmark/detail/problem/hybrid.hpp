#pragma once

#include <cmath>
#include <numeric>

#include "cecxx/benchmark/detail/context.hpp"
#include "cecxx/benchmark/detail/geom.hpp"

namespace cecxx::benchmark::detail {

auto calc_hybrid_chunks(std::ranges::range auto &&mix_ratios,
                        const std::integral auto dim) {
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

template <typename... F> class hybrid_problem {
public:
  hybrid_problem(std::tuple<F...> compounds,
                 std::vector<double> compound_ratios)
      : compounds{compounds}, compound_ratios{std::move(compound_ratios)} {}

  auto operator()(std::span<const double> input, problem_context_view ctx,
                  affine_mask_t mask = {
                      .rot = do_affine_trans::yes,
                      .shift = do_affine_trans::yes}) const -> double {
    constexpr auto fn_indxs =
        std::make_index_sequence<std::tuple_size_v<decltype(compounds)>>();
    const auto partial_eval = invoke_impl(input, ctx, mask, fn_indxs);
    return std::accumulate(partial_eval.begin(), partial_eval.end(), 0.0,
                           std::plus{});
  }

private:
  template <std::size_t... CompoundIndices>
  auto invoke_impl(std::span<const double> input, problem_context_view ctx,
                   affine_mask_t mask,
                   std::index_sequence<CompoundIndices...>) const {
    const auto [sizes, offsets] =
        calc_hybrid_chunks(compound_ratios, input.size());
    auto [y, z] = apply_geom_transformations(input, ctx, mask);
    shufflefunc(z, y, ctx.shuffle);

    auto partial_eval =
        std::array<double, std::tuple_size_v<decltype(compounds)>>{};
    (
        [&](auto) {
          auto comp_fn = std::get<CompoundIndices>(compounds);
          const auto partial_input = std::span{y}.subspan(
              offsets[CompoundIndices], sizes[CompoundIndices]);
          partial_eval[CompoundIndices] = comp_fn(
              partial_input, ctx,
              {.rot = do_affine_trans::no, .shift = do_affine_trans::no}, y);
        }(CompoundIndices),
        ...);

    return partial_eval;
  }

  std::tuple<F...> compounds{};
  std::vector<double> compound_ratios{};
};
} // namespace cecxx::benchmark::detail
