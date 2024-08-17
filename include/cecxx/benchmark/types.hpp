#pragma once

#include <functional>
#include <span>
#include <string>
#include <unordered_set>
#include <vector>

#include "edition.hpp"

namespace cecxx::benchmark {

struct optimizer_output {
  double best_value{};
  std::vector<double> best_values{};
};

// clang-format off
template <typename Optimizer>
concept benchmark_optimizer =
  requires(Optimizer optimizer, std::vector<double> start_point) {
    { optimizer.name() } -> std::same_as<std::string>;
    { optimizer(std::function<double(std::span<double>)>{}, start_point) } -> std::same_as<optimizer_output>;
};
// clang-format on

enum class budget_sample_policy {
  pre_cec_2022,
  post_cec_2022,
};

struct benchmark_options {
  cec_edition_t edition{};
  int max_trials_num{};
  std::vector<std::size_t> dimensions{};
  std::unordered_set<int> excluded_problems{};
  budget_sample_policy sample_policy{budget_sample_policy::post_cec_2022};
  int max_function_evals{};
  double tol_fun{1e-8};
  int max_concurrency_level{10};
};
}  // namespace cecxx::benchmark
