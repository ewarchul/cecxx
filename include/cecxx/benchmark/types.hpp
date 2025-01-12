#pragma once

#include "cecxx/mdspan.hpp"
#include <span>
#include <vector>
namespace cecxx::benchmark {

enum class budget_sample_policy {
    pre_cec_2022,
    post_cec_2022,
};

enum class cec_edition_t { cec2017 };

template <typename T>
using table_data = std::vector<T>;

enum class table_type_t { rotate, shift, shuffle };

enum class do_affine_trans : bool { yes = true, no = false };

struct affine_mask_t {
    do_affine_trans rot{};
    do_affine_trans shift{};
    do_affine_trans shuffle{};
    double rate{1.0};
};

using dimension_t = unsigned int;
using problem_number_t = unsigned int;

using matrix_t = mdspan<const double, extents<std::size_t, std::dynamic_extent, std::dynamic_extent>>;

} // namespace cecxx::benchmark
