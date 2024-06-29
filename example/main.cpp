#include <fmt/base.h>
#include <fmt/chrono.h>
#include <fmt/ranges.h>

#include <chrono>
#include <range/v3/all.hpp>
#include <range/v3/range/conversion.hpp>
#include <range/v3/view/cartesian_product.hpp>
#include <vector>

#include "cecxx/benchmark/evaluator.hpp"

namespace rv = ranges::views;
using namespace cecxx;

auto main() -> int {
  try {
    const auto dimensions = std::vector{10ul, 30ul, 50ul, 100ul};

    // Create an evaluator object for the CEC2017 benchmark
    auto cec2017_eval =
        benchmark::evaluator(cecxx::benchmark::cec_edition_t::cec2017,
                             dimensions, DATA_STORAGE_PATH);

    // create problem grid [problem_number X dimension]
    const auto problem_grid =
        rv::cartesian_product(dimensions, rv::closed_iota(1, 30));

    // Evaluate given input on each optimization problem from CEC2017/D{10, 30,
    // 50, 100}
    const auto start = std::chrono::system_clock::now();
    for (const auto &[dim, fn] : problem_grid) {
      // Prepare input which resembles multidimensional array
      const auto input = std::vector<std::vector<f64>>{
          rv::repeat(0.0) | rv::take(dim) | ranges::to_vector};
      auto output = cec2017_eval(fn, input);
      fmt::println("dim = {}, fn = {}, output = {:}", dim, fn, output);
    }

    fmt::println("Elapsed time: {}",
                 std::chrono::duration_cast<std::chrono::microseconds>(
                     std::chrono::system_clock::now() - start));

    // Create a closure for 1st optimizaiton problem from CEC2017/D50
    const auto input = std::vector<std::vector<f64>>{
        rv::repeat(0.0) | rv::take(50) | ranges::to_vector};

    const auto first_problem = [eval = cec2017_eval](const auto &xs) {
      return eval(11, xs);
    };

    auto output = first_problem(input);
    fmt::println("fn = 11, output = {}", output);

  } catch (std::exception &e) {
    fmt::println("Error: {}", e.what());
  }

  return EXIT_SUCCESS;
}
