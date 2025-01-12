#include <cecxx/benchmark/cec_2017/consts.hpp>
#include <cecxx/benchmark/helpers.hpp>
#include <cecxx/benchmark/types.hpp>
#include <utility>

namespace cecxx::benchmark {
auto is_valid_dimension(const cec_edition_t cec, const dimension_t nrow) -> bool {
    using enum cec_edition_t;
    switch (cec) {
        case cec2017:
            return cec_2017::VALID_DIMENSIONS.contains(nrow);
    }

    std::unreachable();
}

auto get_cec_offset(const cec_edition_t cec, const problem_number_t fn) -> double {
    using enum cec_edition_t;
    switch (cec) {
        case cec2017:
            return cec_2017::OFFSETS.at(fn);
    }

    std::unreachable();
}

auto total_problem_num(const cec_edition_t edition) -> int {
    switch (edition) {
        case cec_edition_t::cec2017:
            return 30;
    }

    std::unreachable();
}

} // namespace cecxx::benchmark
