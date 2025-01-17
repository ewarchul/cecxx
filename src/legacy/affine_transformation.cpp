/*
 *  Besides C++ features like automatic type deduction and span usage instead of C arrays,
 *  the core of this code is taken from the legacy implementation and shall be rewritten.
 */

#include <cmath>
#include <vector>

#include <cecxx/benchmark/detail/legacy/affine_transformation.hpp>

#include "consts.h"

namespace cecxx::benchmark::detail {
void shufflefunc(std::span<const double> input, std::span<double> output, std::span<const unsigned int> shuffle_vec) {
    for (auto i = 0u; i < output.size(); i++) {
        auto idx = std::max(shuffle_vec[i] - 1, 0u);
        output[i] = input[idx];
    }
}

void shiftfunc(std::span<const double> input, std::span<double> output, std::span<const double> shift_vec) {
    for (auto i = 0u; i < output.size(); i++) {
        output[i] = input[i] - shift_vec[i];
    }
}

void rotatefunc(std::span<const double> input, std::span<double> output, std::span<const double> rotate_mat) {
    const auto nrow = output.size();
    for (auto i = 0u; i < nrow; i++) {
        output[i] = 0;
        for (auto j = 0u; j < nrow; j++) {
            output[i] = output[i] + input[j] * rotate_mat[i * nrow + j];
        }
    }
}

void sr_func(std::span<const double> input, std::span<double> sr_x, std::span<const double> shit_vec,
             std::span<const double> rot_mat, const double sh_rate, const do_affine_trans shift,
             const do_affine_trans rotate, std::span<double> output) {
    const auto nrow = input.size();
    if (std::to_underlying(shift) == 1) {
        if (std::to_underlying(rotate) == 1) {
            shiftfunc(input, output, shit_vec);
            for (auto i = 0u; i < nrow; i++) {
                output[i] = output[i] * sh_rate;
            }
            rotatefunc(output, sr_x, rot_mat);
        } else {
            shiftfunc(input, sr_x, shit_vec);
            for (auto i = 0u; i < nrow; i++) {
                sr_x[i] = sr_x[i] * sh_rate;
            }
        }
    } else {
        if (std::to_underlying(rotate) == 1) {
            for (auto i = 0u; i < nrow; i++) {
                output[i] = input[i] * sh_rate;
            }
            rotatefunc(output, sr_x, rot_mat);
        } else
            for (auto i = 0u; i < nrow; i++) {
                sr_x[i] = input[i] * sh_rate;
            }
    }
}

void cf_cal(std::span<const double> input, std::span<double> output, std::span<const double> shift_vec,
            std::span<const double> delta, std::span<const double> bias, std::span<double> fit, unsigned int cf_num) {
    const auto nrow = input.size();
    auto w = std::vector<double>(cf_num);
    double w_max = 0, w_sum = 0;
    for (auto i = 0u; i < cf_num; i++) {
        fit[i] += bias[i];
        w[i] = 0;
        for (auto j = 0u; j < nrow; j++) {
            w[i] += pow(input[j] - shift_vec[i * nrow + j], 2.0);
        }
        if (w[i] != 0) {
            w[i] = pow(1.0 / w[i], 0.5) * exp(-w[i] / 2.0 / static_cast<double>(nrow) / pow(delta[i], 2.0));
        } else {
            w[i] = INF;
        }
        if (w[i] > w_max) {
            w_max = w[i];
        }
    }

    for (auto i = 0u; i < cf_num; i++) {
        w_sum = w_sum + w[i];
    }
    if (w_max == 0) {
        for (auto i = 0u; i < cf_num; i++) {
            w[i] = 1;
        }
        w_sum = static_cast<double>(cf_num);
    }
    output[0] = 0.0;
    for (auto i = 0u; i < cf_num; i++) {
        output[0] = output[0] + w[i] / w_sum * fit[i];
    }
}
} // namespace cecxx::benchmark::detail
