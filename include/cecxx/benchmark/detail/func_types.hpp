#pragma once

#include <span>
#include <vector>

#include "cecxx/benchmark/detail/context.hpp"

namespace cecxx::benchmark::detail {

using stateless_eval_func = double (*)(std::span<const double>);
using local_statefull_eval_func = double (*)(std::span<const double>, problem_context_view, affine_mask_t);
using nonlocal_statefull_eval_func
    = double (*)(std::span<const double>, problem_context_view, affine_mask_t, std::vector<double>);

} // namespace cecxx::benchmark::detail
