/*
 *  Besides C++ features like automatic type deduction and span usage instead of C arrays,
 *  the core of this code is taken from the legacy implementation and shall be rewritten.
 */

#include <cmath>
#include <utility>
#include <vector>

#include <cecxx/benchmark/detail/legacy/affine_transformation.hpp>

#include "cecxx/benchmark/types.hpp"
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
             std::span<const double> rot_mat, const double sh_rate, const double asymm_trans_coeff,
             const do_affine_trans shift, const do_affine_trans rotate, const do_affine_trans asymm_trans,
             const do_affine_trans osymm_trans, std::span<double> output) {
    const auto nrow = input.size();
    if (std::to_underlying(shift) == 1) {
        if (std::to_underlying(rotate) == 1) {
            shiftfunc(input, output, shit_vec);
            for (auto i = 0u; i < nrow; i++) {
                output[i] = output[i] * sh_rate;
            }
            if (std::to_underlying(osymm_trans)) {
                oszfunc(output, sr_x);
            }
            if (std::to_underlying(asymm_trans)) {
                asyfunc(output, sr_x, asymm_trans_coeff);
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

void oszfunc(std::span<const double> input, std::span<double> output) {
    const auto nrow = input.size();
    int sx{};
    double c1{};
    double c2{};
    double xx{};
    for (auto i{0u}; i < nrow; i++) {
        if (i == 0 || i == nrow - 1) {
            if (input[i] != 0) {
                xx = log(fabs(input[i]));
            }

            if (input[i] > 0) {
                c1 = 10;
                c2 = 7.9;
            } else {
                c1 = 5.5;
                c2 = 3.1;
            }
            if (input[i] > 0) {
                sx = 1;
            } else if (input[i] == 0) {
                sx = 0;
            } else {
                sx = -1;
            }
            output[i] = sx * exp(xx + 0.049 * (sin(c1 * xx) + sin(c2 * xx)));
        } else
            output[i] = input[i];
    }
}
void asyfunc(std::span<const double> input, std::span<double> output, double beta_coeff) {
    for (auto i{0u}; i < input.size(); ++i) {
        if (input[i] > 0) {
            output[i] = std::pow(input[i],
                                 1.0 + beta_coeff * i / (static_cast<double>(input.size()) - 1) * pow(input[i], 0.5));
        }
    }
}

} // namespace cecxx::benchmark::detail
