#pragma once

#include <cecxx/benchmark/types.hpp>

namespace cecxx::benchmark {
auto is_valid_dimension(const cec_edition_t cec, const dimension_t nrow) -> bool;

auto get_cec_offset(const cec_edition_t cec, const problem_number_t fn) -> double;

inline constexpr auto total_problem_num(const cec_edition_t edition) -> int {
    using enum cec_edition_t;
    switch (edition) {
        case cec2014:
        case cec2017:
            return 30;
    }

    std::unreachable();
}

inline constexpr auto valid_dimensions(const cec_edition_t edition) -> std::vector<dimension_t> {
    using enum cec_edition_t;
    switch (edition) {
        case cec2014:
            return {10, 30, 50, 100};
        case cec2017:
            return {10, 30, 50, 100};
    }

    std::unreachable();
}

} // namespace cecxx::benchmark
