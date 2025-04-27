/*
 *  Besides C++ features like automatic type deduction and span usage instead of C arrays,
 *  the core of this code is taken from the legacy implementation and shall be rewritten.
 */

// TODO: rewrite

#pragma once

#include <cecxx/benchmark/types.hpp>
#include <span>

namespace cecxx::benchmark::detail {
void shufflefunc(std::span<const double> input, std::span<double> output, std::span<const unsigned int> shuffle_vec);
void shiftfunc(std::span<const double> input, std::span<double> output, std::span<const double> shift_vec);
void rotatefunc(std::span<const double> input, std::span<double> output, std::span<const double> rotate_mat);
void sr_func(std::span<const double> input, std::span<double> sr_x, std::span<const double> shit_vec,
             std::span<const double> rot_mat, const double sh_rate, const do_affine_trans shift,
             const do_affine_trans rotate, std::span<double> output);
void cf_cal(std::span<const double> input, std::span<double> output, std::span<const double> shift_vec,
            std::span<const double> delta, std::span<const double> bias, std::span<double> fit, unsigned int cf_num);

// NOTE:  No idea what `osz` means: ortho-symmetric?
void oszfunc(std::span<const double> input, std::span<double> output);
void asyfunc(std::span<const double> input, std::span<double> output, double beta_coeff);
} // namespace cecxx::benchmark::detail
