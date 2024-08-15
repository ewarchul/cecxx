#include <fmt/base.h>
#include <fmt/chrono.h>
#include <fmt/ranges.h>

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
    constexpr auto spec =
        benchmark::benchmark_specification{.edition = cecxx::benchmark::cec_edition_t::cec2017,
                                           .max_trials_num = 50,
                                           .dimension = 10,
                                           .max_function_evals = 1000,
                                           .max_concurrency_level = 10};

    auto runner = cecxx::benchmark::runner(spec);
    runner.run(dummy_optimizer{"dummy-optimizer"}).get();
  } catch (std::exception &e) {
    fmt::println("Error: {}", e.what());
  }
  return EXIT_SUCCESS;
}
