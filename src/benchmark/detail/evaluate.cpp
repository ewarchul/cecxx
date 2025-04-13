#include <cecxx/benchmark/cec_2013/problem_evaluation_mappings.hpp>
#include <cecxx/benchmark/cec_2014/problem_evaluation_mappings.hpp>
#include <cecxx/benchmark/cec_2017/problem_evaluation_mappings.hpp>
#include <cecxx/benchmark/detail/evaluate.hpp>

namespace cecxx::benchmark::detail {

auto evaluate_selected_problem(cec_edition_t cec, problem_context_view_t ctx, const problem_number_t fn,
                               std::span<const double> input) -> double {
    using enum cec_edition_t;
    switch (cec) {
        case cec2013:
            return cec_2013::evaluate(ctx, fn, input);
        case cec2014:
            return cec_2014::evaluate(ctx, fn, input);
        case cec2017:
            return cec_2017::evaluate(ctx, fn, input);
    }

    std::unreachable();
}

} // namespace cecxx::benchmark::detail
