#include <cecxx/benchmark/runner.hpp>
#include <numeric>

#include "optimizer.hpp"

using namespace std::chrono_literals;
using namespace cecxx;

auto sphere_problem(std::span<double> xs) -> double {
  return std::accumulate(xs.begin(), xs.end(), 0.0,
                         [](const auto acc, const auto x) { return acc + x * x; });
}

auto main() -> int {
  try {
    const auto options =
        benchmark::benchmark_options{.edition = cecxx::benchmark::cec_edition_t::cec2017,
                                     .max_trials_num = 10,
                                     .dimensions = {10, 30},
                                     .max_function_evals = 1000,
                                     .max_concurrency_level = 4};

    auto runner = cecxx::benchmark::runner{options};
    runner(dummy_optimizer{"dummy-optimizer"}).get();
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return EXIT_SUCCESS;
}
