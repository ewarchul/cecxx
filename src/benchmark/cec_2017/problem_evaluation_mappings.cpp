#include <cecxx/benchmark/cec_2017/basic_problems.hpp>
#include <cecxx/benchmark/cec_2017/complex_problems.hpp>
#include <cecxx/benchmark/cec_2017/hybrid_problems.hpp>
#include <cecxx/benchmark/cec_2017/problem_evaluation_mappings.hpp>
#include <utility>

namespace cecxx::benchmark::cec_2017 {

auto evaluate(detail::problem_context_view_t ctx, const problem_number_t fn, std::span<const double> input) -> double {
    switch (fn) {
        case 1:
            return basic_1(input, ctx);
        case 2:
            return basic_2(input, ctx);
        case 3:
            return basic_3(input, ctx);
        case 4:
            return basic_4(input, ctx);
        case 5:
            return basic_5(input, ctx);
        case 6:
            return basic_6(input, ctx);
        case 7:
            return basic_7(input, ctx);
        case 8:
            return basic_8(input, ctx);
        case 9:
            return basic_9(input, ctx);
        case 10:
            return basic_10(input, ctx);
        case 11:
            return hybrid_1(input, ctx);
        case 12:
            return hybrid_2(input, ctx);
        case 13:
            return hybrid_3(input, ctx);
        case 14:
            return hybrid_4(input, ctx);
        case 15:
            return hybrid_5(input, ctx);
        case 16:
            return hybrid_6(input, ctx);
        case 17:
            return hybrid_7(input, ctx);
        case 18:
            return hybrid_8(input, ctx);
        case 19:
            return hybrid_9(input, ctx);
        case 20:
            return hybrid_10(input, ctx);
        case 21:
            return complex_1(input, ctx);
        case 22:
            return complex_2(input, ctx);
        case 23:
            return complex_3(input, ctx);
        case 24:
            return complex_4(input, ctx);
        case 25:
            return complex_5(input, ctx);
        case 26:
            return complex_6(input, ctx);
        case 27:
            return complex_7(input, ctx);
        case 28:
            return complex_8(input, ctx);
        case 29:
            return complex_9(input, ctx);
        case 30:
            return complex_10(input, ctx);
    }
    std::unreachable();
}

} // namespace cecxx::benchmark::cec_2017
