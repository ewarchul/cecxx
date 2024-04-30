## Usage

```cpp

#include <cecxx/cecxx.hpp>
...

namespace rv = ranges::views;

auto main() -> int {
  try {
    // Create an evaluator object for the CEC2017 benchmark
    auto cec2017_eval =
        cecxx::evaluator(cecxx::cec_edition_t::cec2017, DIMENSION, CEC_STORAGE);

    // Prepare input which resembles multidimensional array
    const auto input = std::vector<std::vector<double>>{
        rv::repeat(20.0) | rv::take(DIMENSION) | ranges::to_vector};

    // Evaluate given input on each optimization problem from CEC2017
    const auto start = std::chrono::system_clock::now();
    for (const auto& fn : rv::closed_iota(1, 30)) {
      auto output = cec2017_eval(fn, input);
      fmt::println("fn = {}, output = {}", fn, output);
    }
    fmt::println("Elapsed time: {}",
                 std::chrono::duration_cast<std::chrono::nanoseconds>(
                     std::chrono::system_clock::now() - start));

    // Create a closure for 1st optimizaiton problem from CEC2017
    const auto first_fn = [eval = cec2017_eval](const auto& xs) {
      return eval(1, xs);
    };
    auto output = first_fn(input);
    fmt::println("fn = 1, output = {}", output);

  } catch (std::exception& e) {
    fmt::println("Error: {}", e.what());
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
```
