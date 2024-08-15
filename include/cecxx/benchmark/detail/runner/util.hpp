#pragma once

#include <concurrencpp/concurrencpp.h>

namespace cecxx::benchmark::runner::detail {

template <typename T, typename Executor>
auto invoke_when_any(std::shared_ptr<Executor> executor,
                     std::vector<concurrencpp::result<T>> results,
                     std::invocable<T> auto &&callable)
    -> concurrencpp::result<void> {
  while (not results.empty()) {
    auto when_any_result = co_await concurrencpp::when_any(
        executor, results.begin(), results.end());
    auto finished_task =
        std::move(when_any_result.results[when_any_result.index]);
    auto task_result = co_await finished_task;
    callable(task_result);
    results = std::move(when_any_result.results);
    results.erase(results.begin() + when_any_result.index);
  }
}

struct run_problem_trials_fn {
  auto operator()(benchmark_optimizer auto &&optimizer,
                  benchmark_task task) const -> trial_result {
    auto budget_step_errors = trial_error_table{};
    auto best_so_far_errors = std::vector<double>{};
    auto problem_optimum = problem_optimum_value(task.problem_num);

    for (const auto trial_num : std::ranges::views::iota(0, task.trials_num)) {
      auto result = optimizer(task.eval_fn, make_runif_vector(task.dimension));
      best_so_far_errors.push_back(result.best_value - problem_optimum);

      auto errors = std::vector<double>(task.budget_steps.size());
      std::transform(
          task.budget_steps.begin(), task.budget_steps.end(), errors.begin(),
          [&result, problem_optimum](const auto &budget_step) {
            auto selected_index = std::min(
                0.0, std::ceil(budget_step * result.best_values.size()));
            return std::abs(result.best_values[selected_index] -
                            problem_optimum);
          });
      budget_step_errors[trial_num] = std::move(errors);
    }

    return trial_result{budget_step_errors, best_so_far_errors};
  }
};

inline run_problem_trials_fn run_problem_trials{};

auto make_runif_vector(const int dim) -> std::vector<double> {
  return std::vector<double>(dim);
}

auto problem_optimum_value(int fn_num) -> double { return 10.0; }

void save_trial_results(trial_result) {
  std::cout << "saving trial results on fs...\n";
}

} // namespace cecxx::benchmark::runner::detail
