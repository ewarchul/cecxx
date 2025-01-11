#pragma once

#include <filesystem>
#include <span>
#include <unordered_map>

#include "cecxx/benchmark/types.hpp"

namespace cecxx::benchmark::detail {
struct problem_context_t {
    std::vector<double> shift{};
    std::vector<double> rotate{};
    std::vector<unsigned int> shuffle{};
};

struct problem_context_view_t {
    std::span<const double> shift{};
    std::span<const double> rotate{};
    std::span<const unsigned int> shuffle{};
};

auto make_problem_context_view(const problem_context_t &p_ctx) -> problem_context_view_t;

class benchmark_context_t {
public:
    benchmark_context_t(const cec_edition_t edition, const std::filesystem::path &storage,
                        std::span<const dimension_t> dims);

    auto shift(const problem_number_t fn, const dimension_t dim) const -> table_data<double>;
    auto rotate(const problem_number_t fn, const dimension_t dim) const -> table_data<double>;
    auto shuffle(const problem_number_t fn, const dimension_t dim) const -> table_data<unsigned int>;

    auto problem_context_view(const problem_number_t fn, const dimension_t dim) const -> problem_context_view_t;
    auto copy_problem_context(const problem_number_t fn, const dimension_t dim) const -> problem_context_t;

private:
    template <typename Number>
    using geom_transfrom_fn_grid = std::unordered_map<problem_number_t, table_data<Number>>;

    template <typename Number>
    using geom_transform_dim_fn_grid = std::unordered_map<dimension_t, geom_transfrom_fn_grid<Number>>;

    geom_transform_dim_fn_grid<double> rotate_{};
    geom_transform_dim_fn_grid<unsigned int> shuffle_{};
    geom_transform_dim_fn_grid<double> shift_{};
};

} // namespace cecxx::benchmark::detail
