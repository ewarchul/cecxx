#pragma once

#include <filesystem>
#include <vector>

#include "cecxx/benchmark/concepts.hpp"
#include "cecxx/benchmark/defaults.hpp"
#include "cecxx/benchmark/detail/context.hpp"
#include "cecxx/benchmark/detail/util.hpp"
#include "cecxx/benchmark/edition.hpp"

namespace cecxx::benchmark {

class evaluator {
public:
  evaluator(const cec_edition_t edition, std::span<const usize> dimensions,
            const std::filesystem::path &storage =
                detail::default_benchmark_datadir());

  auto operator()(const usize fn, const matrix<double> auto &input) const
      -> std::vector<double> {
    const auto nrow = input.at(0).size();
    return detail::dispatch_cec(
        edition_, ctx_.problem_context(fn, nrow), fn, input);
  }

private:
  detail::context_t ctx_;
  cec_edition_t edition_{};
};

} // namespace cecxx::benchmark
