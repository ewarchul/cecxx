#pragma once

#include <spdlog/fmt/chrono.h>
#include <spdlog/spdlog.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/cartesian_product.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/transform.hpp>
#include <tuple>

#include "cecxx/benchmark/types.hpp"
#include "types.hpp"

namespace cecxx::benchmark::detail {
namespace rn = ranges;
namespace rv = ranges::views;

auto make_runif_vector(const int dim) -> std::vector<double> {
  return std::vector<double>(static_cast<std::size_t>(dim));
}

auto problem_optimum_value(int fn_num) -> double {
  std::ignore = fn_num;
  return 10.0;
}

void save_trial_results(trial_result) { spdlog::info("Saving trial results on the FS..."); }

auto get_budget_steps(budget_sample_policy policy) -> std::vector<double> { return {1, 2, 3}; }

auto create_benchmark_tasks(benchmark_options options) -> std::vector<benchmark_task> {
  auto benchmark_problem_num = 1;

  auto selected_problems = rv::closed_iota(1, benchmark_problem_num) |
                           rv::filter([excluded = options.excluded_problems](const auto fn_idx) {
                             return not excluded.contains(fn_idx);
                           });

  return rv::cartesian_product(selected_problems, options.dimensions) |
         rv::transform([trials_num = options.max_trials_num, sample_policy = options.sample_policy](
                           const auto &zipped) -> benchmark_task {
           const auto [fn_idx, dim] = zipped;
           return {.dimension = static_cast<int>(dim),
                   .problem_num = fn_idx,
                   .trials_num = trials_num,
                   .budget_steps = get_budget_steps(sample_policy)};
         }) |
         rn::to_vector;
}

namespace impl {
struct run_problem_trials_fn {
  auto operator()(benchmark_optimizer auto optimizer, auto &&evaluation_function,
                  benchmark_task task) const -> trial_result {
    auto budget_distances = trial_distance_table{};
    auto best_so_far_distances = std::vector<double>{};
    auto problem_optimum = problem_optimum_value(task.problem_num);

    const auto trials_start_ts = std::chrono::system_clock::now();
    for (const auto trial_num : rv::iota(0, task.trials_num)) {
      const auto trial_start_ts = std::chrono::system_clock::now();
      spdlog::info(
          "Optimizer [{}] starts solving [{}/{}] trial of the following benchmark problem: "
          "[F-{}/D-{}].",
          optimizer.name(), trial_num + 1, task.trials_num, task.problem_num, task.dimension);

      const auto [best_so_far, best_per_iter] =
          optimizer(evaluation_function, make_runif_vector(task.dimension));

      best_so_far_distances.push_back(best_so_far - problem_optimum);
      budget_distances[trial_num] =
          task.budget_steps |
          rv::transform(
              [&best_per_iter, problem_optimum](const std::floating_point auto budget_step) {
                auto index_at_budget_step =
                    std::min(0.0, std::ceil(budget_step * best_per_iter.size()));
                return std::abs(best_per_iter[index_at_budget_step] - problem_optimum);
              }) |
          rn::to_vector;

      spdlog::info("Optimizer [{}] solved trial [{}/{}] of [F-{}/D-{}] in {}.", optimizer.name(),
                   trial_num + 1, task.trials_num, task.problem_num, task.dimension,
                   std::chrono::duration_cast<std::chrono::milliseconds>(
                       std::chrono::system_clock::now() - trial_start_ts));
    }
    spdlog::info("Optimizer [{}] solved [{}] trials of benchmark problem [F-{}/D-{}] in {}.",
                 optimizer.name(), task.trials_num, task.problem_num, task.dimension,
                 std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::system_clock::now() - trials_start_ts));

    return trial_result{budget_distances, best_so_far_distances};
  }
};
}  // namespace impl

inline constexpr impl::run_problem_trials_fn run_problem_trials{};

}  // namespace cecxx::benchmark::detail
