#pragma once

#include <span>

#include "cecxx/benchmark/detail/types.hpp"

namespace cecxx::benchmark::detail {
void shufflefunc(std::span<const f64> input, std::span<f64> output,
                 std::span<const i64> shuffle_vec);
void shiftfunc(std::span<const f64> input, std::span<f64> output,
               std::span<const f64> shift_vec);
void rotatefunc(std::span<const f64> input, std::span<f64> output,
                std::span<const f64> rotate_mat);
void sr_func(std::span<const f64> input, std::span<f64> sr_x,
             std::span<const f64> shit_vec, std::span<const f64> rot_mat,
             const f64 sh_rate, const do_affine_trans shift,
             const do_affine_trans rotate, std::span<f64> output);
void cf_cal(std::span<const f64> input, std::span<f64> output,
            std::span<const f64> shift_vec, std::span<const f64> delta,
            std::span<const f64> bias, std::span<f64> fit, usize cf_num);
} // namespace cecxx::benchmark::detail
