#pragma once

#include <spdlog/fmt/ranges.h>
#include <spdlog/spdlog.h>

#include "detail/runner/coro.hpp"
#include "detail/runner/types.hpp"
#include "detail/runner/util.hpp"
#include "edition.hpp"
#include "evaluator.hpp"
#include "types.hpp"

namespace cecxx::benchmark {

auto to_string(cec_edition_t e) {
  using enum cec_edition_t;
  switch (e) {
    case cec2017:
      return "CEC-2017";
  }
}

struct runner {
  runner(benchmark_options options)
      : options_{std::move(options)}, evaluator_{options_.edition, options_.dimensions} {
    auto runtime_opts = concurrencpp::runtime_options{};
    runtime_opts.max_cpu_threads = options_.max_concurrency_level;
    runtime_ = std::make_unique<concurrencpp::runtime>(runtime_opts);
    tpe_ = runtime_->thread_pool_executor();
  }

  auto operator()(benchmark_optimizer auto optimizer) -> concurrencpp::result<void> {
    using namespace concurrencpp;
    using namespace detail;
    using optimizer_type = decltype(optimizer);

    const auto tasks = create_benchmark_tasks(options_);
    auto trial_results = std::vector<result<trial_result>>{};
    spdlog::info(
        "Running benchmark with the following settings: edition [{}], thread pool size [{}], dimensions {}, trial number per "
        "problem [{}].",
        to_string(options_.edition), tpe_->max_concurrency_level(), options_.dimensions,
        options_.max_trials_num);

    for (const auto &task : tasks) {
      auto eval_fn = [fn = task.problem_num, eval = evaluator_](const auto &input) {
        return eval(fn, input);
      };
      trial_results.emplace_back(
          tpe_->submit(run_problem_trials, optimizer, std::move(eval_fn), std::move(task)));
    }

    co_await invoke_when_any<trial_result>(tpe_, std::move(trial_results), save_trial_results);
  }

  benchmark_options options_{};
  evaluator evaluator_;
  std::unique_ptr<concurrencpp::runtime> runtime_{};
  std::shared_ptr<concurrencpp::thread_pool_executor> tpe_{};
};

}  // namespace cecxx::benchmark
