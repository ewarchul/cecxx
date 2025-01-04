#include <cstdlib>
#include <print>
#include <ranges>
#include <vector>

#include <cecxx/benchmark/evaluator.hpp>

namespace rn = std::ranges;
namespace rv = std::ranges::views;
using namespace cecxx::benchmark;

// poor man's mdspan
using matrix_t = std::vector<std::vector<double>>;

auto main() -> int {
    try {
        const auto dimensions = std::vector{10u, 30u, 50u, 100u};

        // Create an evaluator object for the CEC2017 benchmark
        auto cec2017_eval = evaluator(cecxx::benchmark::cec_edition_t::cec2017, dimensions, DATA_STORAGE_PATH);

        // Create problem grid [problem_number X dimension]
        const auto problem_grid = rv::cartesian_product(dimensions, rv::iota(1, 30));

        // Evaluate given input on each optimization problem from CEC2017/D{10, 30, 50, 100}
        for (const auto &[dim, fn] : problem_grid) {
            // @TODO replace with mdspan
            // Prepare input which resembles multidimensional array
            const auto input = matrix_t{rv::repeat(0.0) | rv::take(dim) | rn::to<matrix_t::value_type>()};

            const auto output = cec2017_eval(fn, input);
            std::println("dim = {}, fn = {}, output = {}", dim, fn, output[0]);
        }

    } catch (std::exception &e) {
        std::println("Failed: {}", e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
