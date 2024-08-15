#pragma once

#include <algorithm>
#include <cmath>
#include <iostream>
#include <ranges>

#include "cecxx/benchmark/types.hpp"
#include "types.hpp"

namespace cecxx::benchmark::detail {

auto make_runif_vector(const int dim) -> std::vector<double> {
  return std::vector<double>(static_cast<std::size_t>(dim));
}

auto problem_optimum_value(int fn_num) -> double {
  std::ignore = fn_num;
  return 10.0;
}

void save_trial_results(trial_result) { std::cout << "saving trial results on fs...\n"; }

auto create_benchmark_tasks(benchmark_specification) -> std::vector<benchmark_task> { return {}; }

namespace impl {
struct run_problem_trials_fn {
  auto operator()(auto &&optimizer, benchmark_task task) const -> trial_result {
    auto budget_step_errors = trial_distance_table{};
    auto best_so_far_errors = std::vector<double>{};
    auto problem_optimum = problem_optimum_value(task.problem_num);

    for (const auto trial_num : std::ranges::views::iota(0, task.trials_num)) {
      auto result = optimizer(task.evaluation_function, make_runif_vector(task.dimension));
      best_so_far_errors.push_back(result.best_value - problem_optimum);

      auto errors = std::vector<double>(task.budget_steps.size());
      std::transform(task.budget_steps.begin(), task.budget_steps.end(), errors.begin(),
                     [&result, problem_optimum](const auto &budget_step) {
                       auto selected_index =
                           std::min(0.0, std::ceil(budget_step * result.best_values.size()));
                       return std::abs(result.best_values[selected_index] - problem_optimum);
                     });
      budget_step_errors[trial_num] = std::move(errors);
    }

    return trial_result{budget_step_errors, best_so_far_errors};
  }
};
}  // namespace impl

inline constexpr impl::run_problem_trials_fn run_problem_trials{};

}  // namespace cecxx::benchmark::detail
