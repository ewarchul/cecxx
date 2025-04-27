#include "table_io.hpp"

#include <cecxx/benchmark/types.hpp>
#include <format>
#include <print>
#include <utility>

namespace cecxx::benchmark::detail {
using namespace std::string_literals;

namespace {

constexpr auto has_extended_size(const cec_edition_t edition, const problem_number_t fn) -> bool {
    using enum cec_edition_t;
    switch (edition) {
        case cec2013:
            return true;
        case cec2014:
            return (fn - 1) >= 24;
        case cec2017:
            return (fn - 1) >= 21;
    }
    std::unreachable();
}

auto get_func_treshold(const cec_edition_t edition) {
    using enum cec_edition_t;
    switch (edition) {
        case cec2013:
            return 1u;
        case cec2014:
            return 22u;
        case cec2017:
            return 20u;
    }
    std::unreachable();
}

} // namespace

auto ROT_TABLE_FILENAME(const cec_edition_t edition, const std::filesystem::path &datadir, const dimension_t dim,
                        const problem_number_t fn) -> std::string {
    if (edition == cec_edition_t::cec2013) {
        return datadir / std::format("M_D{}.txt", dim);
    }
    return datadir / std::format("M_{}_D{}.txt", fn, dim);
}

auto SHUFFLE_TABLE_FILENAME(const cec_edition_t edition, const std::filesystem::path &datadir, const dimension_t dim,
                            const problem_number_t fn) -> std::string {
    std::ignore = edition;
    return datadir / std::format("shuffle_data_{}_D{}.txt", fn, dim);
}

auto SHIFT_TABLE_FILENAME(const cec_edition_t edition, const std::filesystem::path &datadir, const dimension_t dim,
                          const problem_number_t fn) -> std::string {
    std::ignore = dim;
    if (edition == cec_edition_t::cec2013) {
        return datadir / "shift_data.txt";
    }
    return datadir / std::format("shift_data_{}.txt", fn);
}

auto ROT_TABLE_SIZE(const cec_edition_t edition, const dimension_t dim, const problem_number_t fn) -> table_size_t {
    const auto funcTreshold = get_func_treshold(edition);
    constexpr auto coeff = 10u;
    if (fn - 1 < funcTreshold) {
        return {.size = static_cast<uint>(dim * dim), .scaler = coeff, .scaler_applied = false};
    }
    return {.size = dim * dim * coeff, .scaler = coeff, .scaler_applied = true};
}

auto SHIFT_TABLE_SIZE(const cec_edition_t edition, const dimension_t dim, const problem_number_t fn) -> table_size_t {
    const auto funcTreshold = get_func_treshold(edition);
    constexpr auto coeff = 10u;
    if (fn - 1 < funcTreshold) {
        return {.size = dim, .scaler = coeff, .scaler_applied = false};
    }
    if (edition == cec_edition_t::cec2013 and fn > 20) {
        return {.size = dim * coeff, .scaler = coeff, .scaler_applied = false};
    }
    return {.size = dim * coeff, .scaler = coeff, .scaler_applied = true};
}

auto SHUFFLE_TABLE_SIZE(const cec_edition_t edition, const dimension_t dim, const problem_number_t fn) -> table_size_t {
    constexpr auto coeff = 10u;
    if (not has_extended_size(edition, fn)) {
        return {.size = dim, .scaler = coeff, .scaler_applied = false};
    }

    return {.size = dim * coeff, .scaler = coeff, .scaler_applied = true};
}

} // namespace cecxx::benchmark::detail
