#pragma once

#include <cecxx/mdspan.hpp>
#include <span>
#include <vector>
namespace cecxx::benchmark {

enum class cec_edition_t { cec2013, cec2014, cec2017 };

template <typename T>
using table_data = std::vector<T>;

enum class table_type_t { rotate, shift, shuffle };

enum class do_affine_trans : bool { yes = true, no = false };

struct affine_mask_t {
    do_affine_trans rot{};
    do_affine_trans shift{};
    do_affine_trans shuffle{};
    do_affine_trans asymmetric_trans{do_affine_trans::no};
    do_affine_trans orthosymmetric_trans{do_affine_trans::no};
};

using dimension_t = std::size_t;
using problem_number_t = unsigned int;

using matrix_t = mdspan<const double, extents<std::size_t, std::dynamic_extent, std::dynamic_extent>>;

} // namespace cecxx::benchmark
