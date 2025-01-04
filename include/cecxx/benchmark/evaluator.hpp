#pragma once

#include <filesystem>
#include <vector>

#include "cecxx/benchmark/concepts.hpp"
#include "cecxx/benchmark/defaults.hpp"
#include "cecxx/benchmark/detail/context.hpp"
#include "cecxx/benchmark/detail/evaluate.hpp"
#include "cecxx/benchmark/types.hpp"

namespace cecxx::benchmark {

class evaluator {
public:
    evaluator(const cec_edition_t edition, std::span<const dimension_t> dimensions,
              const std::filesystem::path storage = detail::default_benchmark_datadir());

    auto operator()(const problem_number_t fn, const matrix<double> auto &input) const -> std::vector<double> {
        const auto nrow = input.at(0).size();
        return detail::evaluate(edition_, ctx_.problem_context(fn, nrow), fn, input);
    }

private:
    detail::benchmark_context_t ctx_;
    cec_edition_t edition_{};
};

} // namespace cecxx::benchmark
