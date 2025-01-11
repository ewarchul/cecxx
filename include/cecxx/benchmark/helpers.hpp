#pragma once

#include "cecxx/benchmark/types.hpp"

namespace cecxx::benchmark {
auto is_valid_dimension(const cec_edition_t cec, const dimension_t nrow) -> bool;

auto get_cec_offset(const cec_edition_t cec, const problem_number_t fn) -> double;

auto total_problem_num(const cec_edition_t edition) -> int;

} // namespace cecxx::benchmark
