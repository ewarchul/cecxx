#include "cecxx/benchmark/detail/context.hpp"

#include <algorithm>
#include <print>
#include <ranges>

#include "../table_io.hpp"
#include "cecxx/benchmark/helpers.hpp"
#include "cecxx/benchmark/types.hpp"

namespace cecxx::benchmark::detail {

namespace {
inline auto to_str(const cec_edition_t edition) -> std::string_view {
    switch (edition) {
        case cec_edition_t::cec2017:
            return "cec2017";
    }

    throw std::runtime_error{"Unknown CEC edition"};
}
} // namespace

auto make_problem_context_view(const problem_context_t &p_ctx) -> problem_context_view_t {
    return {
        .shift = p_ctx.shift,
        .rotate = p_ctx.rotate,
        .shuffle = p_ctx.shuffle,
    };
}

benchmark_context_t::benchmark_context_t(const cec_edition_t edition, const std::filesystem::path &storage,
                                         std::span<const dimension_t> dims) {
    const auto datadir = storage / to_str(edition);
    std::ranges::for_each(dims.begin(), dims.end(), [&](const auto dim) {
        for (const auto &fn : std::views::iota(1, total_problem_num(edition) + 1)) {
            auto fn_idx = static_cast<problem_number_t>(fn);
            rotate_[dim].insert({fn_idx, load_table_data<table_type_t::rotate, double>(datadir, dim, fn_idx)});
            shuffle_[dim].insert({fn_idx, load_table_data<table_type_t::shuffle, unsigned int>(datadir, dim, fn_idx)});
            shift_[dim].insert({fn_idx, load_table_data<table_type_t::shift, double>(datadir, dim, fn_idx)});
        }
    });
}

auto benchmark_context_t::shift(const problem_number_t fn, const dimension_t dim) const -> table_data<double> {
    return shift_.at(dim).at(fn);
}
auto benchmark_context_t::rotate(const problem_number_t fn, const dimension_t dim) const -> table_data<double> {
    return rotate_.at(dim).at(fn);
}
auto benchmark_context_t::shuffle(const problem_number_t fn, const dimension_t dim) const -> table_data<unsigned int> {
    return shuffle_.at(dim).at(fn);
}

auto benchmark_context_t::problem_context_view(const problem_number_t fn, const dimension_t dim) const
    -> problem_context_view_t {
    return {.shift = shift_.at(dim).at(fn), .rotate = rotate_.at(dim).at(fn), .shuffle = shuffle_.at(dim).at(fn)};
}

auto benchmark_context_t::copy_problem_context(const problem_number_t fn, const dimension_t dim) const
    -> problem_context_t {
    return {.shift = shift_.at(dim).at(fn), .rotate = rotate_.at(dim).at(fn), .shuffle = shuffle_.at(dim).at(fn)};
}

} // namespace cecxx::benchmark::detail
