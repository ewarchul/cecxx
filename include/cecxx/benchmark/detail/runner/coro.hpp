#include <memory>

#include <concurrencpp/concurrencpp.h>

namespace cecxx::benchmark::detail {

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
} // namespace cecxx::benchmark::detail
