#include <cecxx/benchmark/cec_2014/consts.hpp>
#include <cecxx/benchmark/cec_2017/consts.hpp>
#include <cecxx/benchmark/helpers.hpp>
#include <cecxx/benchmark/types.hpp>
#include <utility>

namespace cecxx::benchmark {
auto is_valid_dimension(const cec_edition_t cec, const dimension_t nrow) -> bool {
    using enum cec_edition_t;
    switch (cec) {
        case cec2014:
            return cec_2014::VALID_DIMENSIONS.contains(nrow);
        case cec2017:
            return cec_2017::VALID_DIMENSIONS.contains(nrow);
    }

    std::unreachable();
}

auto get_cec_offset(const cec_edition_t cec, const problem_number_t fn) -> double {
    using enum cec_edition_t;
    switch (cec) {
        case cec2014:
            return cec_2014::OFFSETS.at(fn);
        case cec2017:
            return cec_2017::OFFSETS.at(fn);
    }

    std::unreachable();
}

} // namespace cecxx::benchmark
