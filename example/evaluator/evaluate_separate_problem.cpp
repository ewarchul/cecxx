#include "cecxx/mdspan.hpp"
#include <cstdlib>
#include <functional>
#include <print>
#include <ranges>
#include <vector>

#include <cecxx/benchmark/evaluator.hpp>

namespace rn = std::ranges;
namespace rv = std::ranges::views;
using namespace cecxx::benchmark;

auto dummy_optimizer(cecxx::benchmark::matrix_t x0, std::function<std::vector<double>(matrix_t)> fn) -> double {
    auto result = fn(x0);
    return result[0];
}

auto main() -> int {
    try {
        constexpr auto dim{50uz};
        // Create an evaluator object for the CEC2017 benchmark for 50D
        auto cec_2017 = evaluator(cecxx::benchmark::cec_edition_t::cec2017, std::vector{dim}, DATA_STORAGE_PATH);

        // Extract problem F3 from CEC2017/D50
        auto fn_3 = cec_2017.extract_problem(3, dim);

        // Prepare starting point for your optimization solver
        const auto data = rv::repeat(0.0) | rv::take(dim) | rn::to<std::vector<double>>();
        const auto x0 = cecxx::mdspan{data.data(), dim, 1};

        // Pass problem F3 to your optimizer together with starting point
        const auto result = dummy_optimizer(x0, fn_3);
        std::println("Dummy optimizer's result: {}", result);
    } catch (std::exception &e) {
        std::println("Failed: {}", e.what());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
