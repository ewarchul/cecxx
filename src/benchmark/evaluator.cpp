#include <cecxx/benchmark/detail/evaluate.hpp>
#include <cecxx/benchmark/evaluator.hpp>

namespace cecxx::benchmark {

evaluator::evaluator(const cec_edition_t edition, std::span<const dimension_t> dimensions,
                     const std::filesystem::path storage)
    : ctx_{edition, storage, dimensions}, edition_{edition} {}

auto evaluator::operator()(const problem_number_t fn, matrix_t input) const -> std::vector<double> {
    const auto nrow = input.extent(0);
    return detail::evaluate(edition_, ctx_.problem_context_view(fn, nrow), fn, input);
}

auto evaluator::extract_problem(const problem_number_t fn, const dimension_t dim)
    -> std::function<std::vector<double>(matrix_t)> {
    auto problem_ctx = ctx_.copy_problem_context(fn, dim);
    return [f = fn, e = edition_, p_ctx = std::move(problem_ctx)](const matrix_t &input) -> std::vector<double> {
        return detail::evaluate(e, std::move(p_ctx), f, input);
    };
}

} // namespace cecxx::benchmark
