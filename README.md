# cecxx

> [!WARNING]  
> This library is under active development. Currently, only the CEC-2017 edition is complete.
> If you want to use slightly better (i.e., without memory leaks) implementations of other editions
> than those proposed by the competition organizers, go to branch [legacy-c](https://github.com/ewarchul/cecxx/tree/legacy-c). 

**cecxx** is an implementation of IEEE Congress on Evolutionary Computation (CEC) benchmarks in C++23. 

## Quick example

```cpp
#include <cstdlib>
#include <print>
#include <ranges>
#include <vector>

#include <cecxx/benchmark/evaluator.hpp>
#include <cecxx/mdspan.hpp>

namespace rn = std::ranges;
namespace rv = std::ranges::views;
using namespace cecxx::benchmark;

auto main() -> int {
    try {
        const auto dimensions = std::vector{10uz, 30uz, 50uz, 100uz};

        // Create an evaluator object for the CEC2017 benchmark
        auto cec_2017 = evaluator(cec_edition_t::cec2017, dimensions);

        // Create problem grid [problem_number X dimension]
        const auto problem_grid = rv::cartesian_product(dimensions, rv::iota(1, 30));

        // Evaluate given input on each optimization problem from CEC2017/D{10, 30, 50, 100}
        for (const auto &[dim, fn] : problem_grid) {
            // Prepare input which matrix [dim x 2]
            const auto input = rv::repeat(0.0) | rv::take(2 * dim) | rn::to<std::vector<double>>();
            const auto mat = cecxx::mdspan{input.data(), dim, 2};

            const auto output = cec_2017(fn, mat);
            std::println("dim = {}, fn = {}, output[0] = {}, output[1] = {}", dim, fn, output[0], output[1]);
        }
    } catch (std::exception &e) {
        std::println("Failed: {}", e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
```

## Documentation

> [!NOTE]
> The full documentation is under development.

