#include "table_io.hpp"

#include "cecxx/benchmark/types.hpp"
#include <format>

namespace cecxx::benchmark::detail {
using namespace std::string_literals;

namespace {

constexpr auto has_extended_size(const problem_number_t fn) -> bool {
    return (fn - 1) >= 21;
}
} // namespace

auto ROT_TABLE_FILENAME(const std::filesystem::path &datadir, const dimension_t dim, const problem_number_t fn)
    -> std::string {
    return datadir / std::format("M_{}_D{}.txt", fn, dim);
}

auto SHUFFLE_TABLE_FILENAME(const std::filesystem::path &datadir, const dimension_t dim, const problem_number_t fn)
    -> std::string {
    return datadir / std::format("shuffle_data_{}_D{}.txt", fn, dim);
}

auto SHIFT_TABLE_FILENAME(const std::filesystem::path &datadir, const dimension_t dim, const problem_number_t fn)
    -> std::string {
    std::ignore = dim;
    return datadir / std::format("shift_data_{}.txt", fn);
}

auto ROT_TABLE_SIZE(const dimension_t dim, const problem_number_t fn) -> table_size_t {
    constexpr auto funcTreshold = 20u;
    constexpr auto coeff = 10u;
    if (fn - 1 < funcTreshold) {
        return {.size = static_cast<uint>(dim * dim), .scaler = coeff, .scaler_applied = false};
    }
    return {.size = dim * dim * coeff, .scaler = coeff, .scaler_applied = true};
}

auto SHIFT_TABLE_SIZE(const dimension_t dim, const problem_number_t fn) -> table_size_t {
    constexpr auto funcTreshold = 20u;
    constexpr auto coeff = 10u;
    if (fn - 1 < funcTreshold) {
        return {.size = dim, .scaler = coeff, .scaler_applied = false};
    }
    return {.size = dim * coeff, .scaler = coeff, .scaler_applied = true};
}

auto SHUFFLE_TABLE_SIZE(const dimension_t dim, const problem_number_t fn) -> table_size_t {
    constexpr auto coeff = 10u;
    if (not has_extended_size(fn)) {
        return {.size = dim, .scaler = coeff, .scaler_applied = false};
    }

    return {.size = dim * coeff, .scaler = coeff, .scaler_applied = true};
}

} // namespace cecxx::benchmark::detail