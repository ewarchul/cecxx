#pragma once

#include <sys/types.h>
#include <vector>

#include "detail/runner/coro.hpp"
#include "detail/runner/types.hpp"
#include "detail/runner/util.hpp"
#include "types.hpp"

namespace cecxx::benchmark {

struct runner {
  runner(benchmark_specification spec) : spec_{std::move(spec)} {
    auto options = concurrencpp::runtime_options{};
    options.max_cpu_threads = spec.max_concurrency_level;
    runtime_ = std::make_unique<concurrencpp::runtime>(options);
    tpe_ = runtime_->thread_pool_executor();
  }

  auto run(benchmark_optimizer auto &&optimizer) -> concurrencpp::result<void> {
    using namespace concurrencpp;
    using namespace detail;
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
