#pragma once

#include "cecxx/benchmark/detail/context.hpp"
#include <cmath>
#include <print>
#include <ranges>
#include <span>
#include <string>
#include <unordered_map>
#include <vector>

namespace cecxx::benchmark::detail {

using partial_result_t = std::unordered_map<std::string, std::vector<double>>;

auto print_vec(auto &&xs) {
    for (auto &&[i, x] : xs | std::ranges::views::enumerate) {
        std::print("({}) {}, ", i, x);
    }
    std::println("");
}

struct rotation {
    bool do_stride{false};
    static constexpr auto name{"rotation"};
    auto operator()(std::span<double> input, problem_context_view_t ctx, affine_mask_t mask, partial_result_t partial)
        -> void {
        std::ignore = partial;
        if (not std::to_underlying(mask.rot)) {
            return;
        }
        auto output = std::vector<double>(input.size());
        const auto nrow = input.size();
        auto stride_ = do_stride ? nrow * nrow : 0;
        for (auto i = 0u; i < nrow; i++) {
            output[i] = 0;
            for (auto j = 0u; j < nrow; j++) {
                output[i] += input[j] * ctx.rotate[stride_ + i * nrow + j];
            }
        }
        for (auto i{0u}; i < nrow; ++i) {
            input[i] = output[i];
        }
    }
};

struct shift {
    static constexpr auto name{"shift"};
    static auto operator()(std::span<double> input, problem_context_view_t ctx, affine_mask_t mask,
                           partial_result_t partial) -> void {
        std::ignore = partial;
        if (not std::to_underlying(mask.shift)) {
            return;
        }
        for (auto i = 0u; i < input.size(); i++) {
            input[i] = input[i] - ctx.shift[i];
        }
    }
};

struct scale {
    static constexpr auto name{"scale"};
    constexpr scale(double numerator = 1.0, double denominator = 1.0) : num_{numerator}, denom_{denominator} {}

    auto operator()(std::span<double> input, problem_context_view_t, affine_mask_t, partial_result_t) -> void {
        for (auto i = 0u; i < input.size(); i++) {
            input[i] = input[i] * num_ / denom_;
        }
    }

    double num_{};
    double denom_{};
};

struct orthosymmetric_trans {
    static constexpr auto name{"orthosymmetric_trans"};
    static auto operator()(std::span<double> input, problem_context_view_t ctx, affine_mask_t mask,
                           partial_result_t partial) -> void {
        std::ignore = ctx;
        std::ignore = mask;
        std::ignore = partial;
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
                input[i] = sx * exp(xx + 0.049 * (sin(c1 * xx) + sin(c2 * xx)));
            }
        }
    }
};

template <typename T = shift>
struct asymmetric_trans {
    static constexpr auto name{"asymmetric_trans"};
    auto operator()(std::span<double> input, problem_context_view_t ctx, affine_mask_t mask, partial_result_t partial) {
        std::ignore = ctx;
        std::ignore = mask;
        for (auto i{0u}; i < input.size(); ++i) {
            if (input[i] > 0) {
                input[i] = std::pow(input[i],
                                    1.0 + coeff * i / (static_cast<double>(input.size()) - 1) * pow(input[i], 0.5));
            } else {
                input[i] = partial.at(last_transformation.name)[i];
            }
        }
    }
    double coeff{};
    T last_transformation{};
};

template <typename T = std::monostate>
struct shift_by_scalar {
    static constexpr auto name{"shift_by_scalar"};

    constexpr shift_by_scalar(double coeff) : coeff_{coeff} {}

    auto operator()(std::span<double> input, problem_context_view_t, affine_mask_t, partial_result_t partial) -> void {
        for (auto i{0u}; i < input.size(); ++i) {
            if constexpr (std::same_as<T, std::monostate>) {
                input[i] += coeff_;
            } else {
                input[i] = partial.at(last_transformation.name)[i] + coeff_;
            }
        }
    }

    double coeff_{0.0};
    T last_transformation{};
};

struct power_scale {
    static constexpr auto name{"power_scale"};
    constexpr void operator()(std::span<double> input, problem_context_view_t, affine_mask_t, partial_result_t) {
        auto output = std::vector<double>(input.size());
        output.assign(input.begin(), input.end());
        for (auto i{0u}; i < input.size() - 1; ++i) {
            output[i] = pow(input[i] * input[i] + input[i + 1] * input[i + 1], 0.5);
        }
        for (auto i{0u}; i < input.size(); ++i) {
            input[i] = output[i];
        }
    }
};

struct power_scale2 {
    static constexpr auto name{"power_scale2"};
    constexpr void operator()(std::span<double> input, problem_context_view_t, affine_mask_t, partial_result_t) {
        auto output = std::vector<double>(input.size());
        output.assign(input.begin(), input.end());
        for (auto i{0u}; i < input.size(); ++i) {
            output[i] = input[i] * pow(10.0 * coeff_, 1.0 * i / (static_cast<double>(input.size()) - 1) / 2.0);
        }
        for (auto i{0u}; i < input.size(); ++i) {
            input[i] = output[i];
        }
    }

    double coeff_{1.0};
};

struct power_scale3 {
    static constexpr auto name{"power_scale3"};
    constexpr void operator()(std::span<double> input, problem_context_view_t, affine_mask_t, partial_result_t) {
        auto output = std::vector<double>(input.size());
        output.assign(input.begin(), input.end());
        for (auto i = 0u; i < input.size(); i++) {
            if (fabs(input[i]) > 0.5)
                output[i] = floor(2 * input[i] + 0.5) / 2;
        }

        for (auto i{0u}; i < input.size(); ++i) {
            input[i] = output[i];
        }
    }
};

struct shuffle {
    static constexpr auto name{"shuffle"};
    constexpr void operator()(std::span<double> input, problem_context_view_t ctx, affine_mask_t, partial_result_t) {
        auto output = std::vector<double>(input.size());
        output.assign(input.begin(), input.end());

        for (auto i{0u}; i < input.size(); ++i) {
            output[i] = input[ctx.shuffle[i] - 1];
        }
        for (auto i{0u}; i < input.size(); ++i) {
            input[i] = output[i];
        }
    }
};

template <typename... AffineTransformation>
auto apply_geom_fns(std::span<const double> input, problem_context_view_t ctx, affine_mask_t mask,
                    std::tuple<AffineTransformation...> affine_fns) -> std::vector<double> {
    auto output = std::vector<double>(input.size());
    output.assign(input.begin(), input.end());
    auto partial = std::unordered_map<std::string, std::vector<double>>{};
    // std::println("input");
    // print_vec(input);
    for_sequence(std::make_index_sequence<std::tuple_size_v<decltype(affine_fns)>>{}, [&](auto i) {
        auto &&fn = std::get<i>(affine_fns);
        fn(output, ctx, mask, partial);
        partial[fn.name] = output;
        // std::println("output {}", fn.name);
        // print_vec(output);
    });
    return output;
}

} // namespace cecxx::benchmark::detail
