#pragma once

#include <vector>

#include "cecxx/benchmark/detail/context.hpp"

namespace cecxx::benchmark::detail {
struct complex_problem_params {
  std::vector<double> deltas{};
  std::vector<double> biases{};
  std::unordered_map<std::size_t, double> scales{};
};

template <typename... F> class complex_problem {
public:
  complex_problem(std::tuple<F...> compounds, complex_problem_params parameters)
      : compounds{compounds}, params{std::move(parameters)} {}

  auto operator()(std::span<const double> input, problem_context_view ctx,
                  affine_mask_t mask = {
                      .rot = do_affine_trans::yes,
                      .shift = do_affine_trans::yes}) const -> double {
    constexpr auto compounds_num{std::tuple_size_v<decltype(compounds)>};
    constexpr auto fn_indxs =
        std::make_index_sequence<std::tuple_size_v<decltype(compounds)>>();
    auto partial_eval = invoke_impl(input, ctx, mask, fn_indxs);
    auto output = std::array<double, 1>{};
    cf_cal(input, output, ctx.shift, params.deltas, params.biases, partial_eval,
           compounds_num);

    return output[0];
  }

private:
  template <std::size_t... CompoundIndex>
  auto invoke_impl(std::span<const double> input, problem_context_view ctx,
                   affine_mask_t mask,
                   std::index_sequence<CompoundIndex...>) const {
    auto partial_eval =
        std::array<double, std::tuple_size_v<decltype(compounds)>>{};
    const auto nrow = input.size();
    (
        [&](auto) {
          auto sub_ctx = problem_context_view{
              .shift = ctx.shift.subspan(nrow * CompoundIndex),
              .rotate = ctx.rotate.subspan(nrow * nrow * CompoundIndex),
              .shuffle = ctx.shuffle.subspan(nrow * CompoundIndex)};
          auto comp_fn = std::get<CompoundIndex>(compounds);
          partial_eval[CompoundIndex] =
              params.scales.at(CompoundIndex) * comp_fn(input, sub_ctx, mask);
        }(CompoundIndex),
        ...);
    return partial_eval;
  }

  std::tuple<F...> compounds{};
  complex_problem_params params{};
};
} // namespace cecxx::benchmark::detail
