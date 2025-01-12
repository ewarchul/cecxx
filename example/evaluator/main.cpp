#include "cecxx/mdspan.hpp"
#include <chrono>
#include <cstdlib>
#include <functional>
#include <print>
#include <ranges>
#include <thread>
#include <vector>

#include <cecxx/benchmark/evaluator.hpp>

namespace rn = std::ranges;
namespace rv = std::ranges::views;
using namespace cecxx::benchmark;

// poor man's mdspan

void optimizer(cecxx::benchmark::matrix_t x0, std::function<std::vector<double>(matrix_t)> fn) {
    std::println("Calculating CEC functions in different thread...");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    auto v = fn(x0);
    auto ff = std::filesystem::path{"f.txt"};

    auto fptr = std::fopen(ff.c_str(), "w");

    std::println(fptr, "Value -> {}", v[0]);
    std::println("Value -> {}", v[0]);

    std::fclose(fptr);
}

auto main() -> int {
    try {
        const auto dimensions = std::vector{10u};

        // Create an evaluator object for the CEC2017 benchmark
        auto cec_2017 = evaluator(cecxx::benchmark::cec_edition_t::cec2017, dimensions, DATA_STORAGE_PATH);

        // Create problem grid [problem_number X dimension]
        const auto problem_grid = rv::cartesian_product(dimensions, rv::iota(1, 30));

        // Evaluate given input on each optimization problem from CEC2017/D{10, 30, 50, 100}
        for (const auto &[dim, fn] : problem_grid) {
            // @TODO replace with mdspan
            // Prepare input which resembles multidimensional array
            const auto input = rv::repeat(0.0) | rv::take(2 * dim) | rn::to<std::vector<double>>();
            const auto mat = cecxx::mdspan{input.data(), dim, 2};

            const auto output = cec_2017(fn, mat);
            std::println("dim = {}, fn = {}, output[0] = {}, output[1] = {}", dim, fn, output[0], output[1]);
        }

        // auto input = matrix_t{rv::repeat(0.0) | rv::take(10) | rn::to<matrix_t::value_type>()};
        // auto fn_3 = cec_2017.extract_problem(3, 10);
        // const auto output = fn_3(input);
        // std::println("dim = {}, fn = {}, output = {}", 10, 3, output[0]);
        // auto worker = std::jthread{optimizer, std::move(input), fn_3};
        // worker.detach();
        // std::println("bye bye from this scope");

    } catch (std::exception &e) {
        std::println("Failed: {}", e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
