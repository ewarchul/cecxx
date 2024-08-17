#pragma once

#include <functional>
#include <span>
namespace cecxx::benchmark::detail {

using trial_num = int;
using optimum_distance = double;
using trial_distance_table = std::unordered_map<trial_num, std::vector<optimum_distance>>;
using trial_distance_vec = std::vector<optimum_distance>;

struct benchmark_task {
  int dimension{};
  int problem_num{};
  int trials_num{};
  std::vector<double> budget_steps{};
};

struct trial_result {
  trial_distance_table budget_step_errors;
  trial_distance_vec best_so_far_errors;
};

}  // namespace cecxx::benchmark::detail
