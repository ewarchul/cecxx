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
  evaluator(const cec_edition_t edition, const u8 dimension,
            const std::filesystem::path &storage =
                detail::default_benchmark_datadir());

  auto operator()(const u8 fn, const matrix<double> auto &input) const
      -> std::vector<double> {
    return detail::dispatch_cec(edition_, ctx_.problem_context(fn), fn, input);
  }

private:
  u8 dim_{};
  detail::context_t ctx_;
  cec_edition_t edition_{};
};

} // namespace cecxx::benchmark
