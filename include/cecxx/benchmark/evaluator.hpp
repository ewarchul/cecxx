#pragma once

#include <filesystem>
#include <functional>
#include <vector>

#include <cecxx/benchmark/defaults.hpp>
#include <cecxx/benchmark/detail/context.hpp>
#include <cecxx/benchmark/types.hpp>

namespace cecxx::benchmark {

class evaluator {
public:
    evaluator(const cec_edition_t edition, std::span<const dimension_t> dimensions,
              const std::filesystem::path storage = detail::default_benchmark_datadir());

    auto operator()(const problem_number_t fn, matrix_t input) const -> std::vector<double>;

    auto extract_problem(const problem_number_t fn, const dimension_t dim)
        -> std::function<std::vector<double>(matrix_t)>;

private:
    detail::benchmark_context_t ctx_;
    cec_edition_t edition_{};
};

} // namespace cecxx::benchmark
