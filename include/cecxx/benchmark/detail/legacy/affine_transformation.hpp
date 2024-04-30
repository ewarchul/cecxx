#pragma once

#include <span>

#include "cecxx/benchmark/detail/types.hpp"

namespace cecxx::benchmark::detail {
void shufflefunc(std::span<const double> input, std::span<double> output, std::span<const int> shuffle_vec);
void shiftfunc(std::span<const double> input, std::span<double> output, std::span<const double> shift_vec);
void rotatefunc(std::span<const double> input, std::span<double> output, std::span<const double> rotate_mat);
void sr_func(std::span<const double> input, std::span<double> sr_x, std::span<const double> shit_vec,
             std::span<const double> rot_mat, const double sh_rate, const do_affine_trans shift,
             const do_affine_trans rotate, std::span<double> output);
void cf_cal(std::span<const double> input, std::span<double> output, std::span<const double> shift_vec,
            std::span<const double> delta, std::span<const double> bias, std::span<double> fit, int cf_num);
}  // namespace cecxx::benchmark::detail
