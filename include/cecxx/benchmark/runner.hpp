#pragma once

#include <functional>
#include <span>
#include <string>
#include <sys/types.h>
#include <vector>

#include "detail/runner/coro_util.hpp"
#include "detail/runner/types.hpp"
#include "detail/runner/util.hpp"
#include "edition.hpp"

#include <concurrencpp/concurrencpp.h>

namespace cecxx::benchmark {

struct optimizer_output {
  double best_value{};
  std::vector<double> best_values{};
  int function_eval_num{};
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

struct benchmark_specification {
  cec_edition_t edition{};
  int max_trials_num{};
  int dimension{};
  std::vector<int> excluded_problems{};
  budget_sample_policy sample_policy{budget_sample_policy::post_cec_2022};
  int max_function_evals{};
  double tol_fun{1e-8};
  int max_concurrency_level{10};
};

struct benchmark_runner {
  benchmark_runner(benchmark_specification spec) : spec_{std::move(spec)} {
    auto options = concurrencpp::runtime_options{};
    options.max_cpu_threads = spec.max_concurrency_level;
    runtime_ = std::make_unique<concurrencpp::runtime>(options);
    tpe_ = runtime_->thread_pool_executor();
  }

  auto run(benchmark_optimizer auto &&optimizer) -> concurrencpp::result<void> {
    using namespace concurrencpp;
    using namespace runner::detail;
    using optimizer_type = decltype(optimizer);

    auto trial_results = std::vector<result<trial_result>>{};
    const auto tasks = create_benchmark_tasks(spec_);
    for (const auto &task : tasks) {
      trial_results.emplace_back(tpe_->submit(
          run_problem_trials, std::forward<optimizer_type>(optimizer), task));
    }
    co_await invoke_when_any<trial_result>(tpe_, std::move(trial_results),
                                           save_trial_results);
  }

  benchmark_specification spec_{};
  std::unique_ptr<concurrencpp::runtime> runtime_{};
  std::shared_ptr<concurrencpp::thread_pool_executor> tpe_{};
};

} // namespace cecxx::benchmark
