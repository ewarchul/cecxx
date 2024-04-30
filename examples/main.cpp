#include <fmt/base.h>
#include <fmt/chrono.h>
#include <fmt/ranges.h>

#include <chrono>
#include <range/v3/all.hpp>
#include <vector>

#include "cecxx/benchmark/evaluator.hpp"

constexpr auto DIMENSION{10};
constexpr auto CEC_STORAGE{"/home/ewarchul/open-source/optim/cec/data"};

namespace rv = ranges::views;

auto main() -> int {
  try {
    // Create an evaluator object for the CEC2017 benchmark
    auto cec2017_eval = cecxx::benchmark::evaluator(cecxx::benchmark::cec_edition_t::cec2017, DIMENSION, CEC_STORAGE);

    // Prepare input which resembles multidimensional array
    const auto input = std::vector<std::vector<double>>{rv::repeat(10.0) | rv::take(DIMENSION) | ranges::to_vector};

    // Evaluate given input on each optimization problem from CEC2017
    const auto start = std::chrono::system_clock::now();
    for (const auto& fn : rv::closed_iota(1, 30)) {
      auto output = cec2017_eval(fn, input);
      fmt::println("fn = {}, output = {:}", fn, output);
    }
    fmt::println("Elapsed time: {}",
                 std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - start));

    return EXIT_SUCCESS;
    // Create a closure for 1st optimizaiton problem from CEC2017
    const auto first_fn = [&eval = cec2017_eval](const auto& xs) { return eval(11, xs); };
    auto output = first_fn(input);
    //   fmt::println("fn = 11, output = {}", output);

  } catch (std::exception& e) {
    fmt::println("Error: {}", e.what());
  }

  return EXIT_SUCCESS;
}
