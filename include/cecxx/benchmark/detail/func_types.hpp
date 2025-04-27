#pragma once

#include <span>

#include <cecxx/benchmark/detail/context.hpp>

namespace cecxx::benchmark::detail {

using contextless_eval_func = double (*)(std::span<const double>);
using contextful_eval_func = double (*)(std::span<const double>, problem_context_view_t, affine_mask_t);

} // namespace cecxx::benchmark::detail
