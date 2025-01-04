#include "cecxx/benchmark/detail/context.hpp"

#include <algorithm>
#include <ranges>

#include "cecxx/benchmark/types.hpp"
#include "table_io.hpp"
#include "util.hpp"

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

context_t::context_t(const cec_edition_t edition, const std::filesystem::path &storage,
                     std::span<const dimension_t> dims) {
    const auto datadir = storage / to_str(edition);
    std::ranges::for_each(dims.begin(), dims.end(), [&](const auto dim) {
        for (const auto &fn : std::views::iota(1, total_problem_num(edition) + 1)) {
            auto fn_idx = static_cast<problem_number_t>(fn);
            rotate_[dim].insert({fn_idx, load_table_data<table_type_t::rotate, double>(datadir, dim, fn_idx)});
            shuffle_[dim].insert({fn_idx, load_table_data<table_type_t::shuffle, int>(datadir, dim, fn_idx)});
            shift_[dim].insert({fn_idx, load_table_data<table_type_t::shift, double>(datadir, dim, fn_idx)});
        }
    });
}

auto context_t::shift(const problem_number_t fn, const dimension_t dim) const {
    return shift_.at(dim).at(fn);
}
auto context_t::rotate(const problem_number_t fn, const dimension_t dim) const {
    return rotate_.at(dim).at(fn);
}
auto context_t::shuffle(const problem_number_t fn, const dimension_t dim) const {
    return shuffle_.at(dim).at(fn);
}
auto context_t::problem_context(const problem_number_t fn, const dimension_t dim) const {
    return problem_context_view{
        .shift = shift_.at(dim).at(fn), .rotate = rotate_.at(dim).at(fn), .shuffle = shuffle_.at(dim).at(fn)};
}

} // namespace cecxx::benchmark::detail
