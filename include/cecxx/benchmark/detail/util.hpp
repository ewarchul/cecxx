#pragma once

#include "cecxx/benchmark/edition.hpp"
#include "cecxx/benchmark/detail/context.hpp"
#include "cecxx/benchmark/detail/cec2017/evaluate.hpp"

namespace cecxx::benchmark::detail {
auto dispatch_cec(cec_edition_t edition, problem_context_view ctx, const int fn_num, const auto& input) {
  switch (edition) {
  case cec_edition_t::cec2017:
    return cec2017::evaluate(ctx, fn_num, input);
  }

  throw std::runtime_error{"Unknown CEC edition"};
}

}  // namespace cecxx::detail