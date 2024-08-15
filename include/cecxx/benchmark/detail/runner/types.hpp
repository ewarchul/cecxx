#pragma once

#include <functional>
#include <span>
namespace cecxx::benchmark::runner::detail {

using trial_num = int;
using optimum_distance = double;
using trial_error_table = std::unordered_map<trial_num, std::vector<optimum_distance>>;
using trial_error_vec = std::vector<optimum_distance>;

struct benchmark_task {
  int dimension{};
  int problem_num{};
  int trials_num{1};
  std::function<double(std::span<double>)> eval_fn{};
  std::vector<double> budget_steps{};
};

struct trial_result {
  trial_error_table budget_step_errors;
  trial_error_vec best_so_far_errors;
};

} // namespace cecxx::benchmark::runner::detail
