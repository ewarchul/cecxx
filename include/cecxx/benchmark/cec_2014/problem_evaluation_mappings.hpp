#pragma once

#include <cecxx/benchmark/detail/context.hpp>
#include <cecxx/benchmark/types.hpp>

namespace cecxx::benchmark::cec_2014 {

auto evaluate(detail::problem_context_view_t ctx, const problem_number_t fn, std::span<const double> input) -> double;

} // namespace cecxx::benchmark::cec_2014
