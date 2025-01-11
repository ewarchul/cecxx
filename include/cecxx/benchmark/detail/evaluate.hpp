#pragma once

#include "cecxx/benchmark/concepts.hpp"
#include "cecxx/benchmark/detail/context.hpp"
#include "cecxx/benchmark/helpers.hpp"
#include "cecxx/benchmark/types.hpp"

#include "cecxx/benchmark/cec_2017/problem_evaluation_mappings.hpp"
#include "cecxx/detail/mdspan/__p0009_bits/full_extent_t.hpp"
#include "cecxx/detail/mdspan/mdspan"
#include <concepts>
#include <type_traits>
#include <utility>

namespace cecxx::benchmark::detail {

auto evaluate_selected_problem(cec_edition_t cec, problem_context_view_t ctx, const problem_number_t fn,
                               const auto &input) -> double {
    using enum cec_edition_t;
    switch (cec) {
        case cec2017:
            return cec_2017::evaluate(ctx, fn, input);
    }

    std::unreachable();
}

auto evaluate(cec_edition_t cec, problem_context auto &&, const problem_number_t fn, mat_2 input) {
    const auto nrow = input.extent(0);
    const auto ncol = input.extent(1);

    if (not is_valid_dimension(cec, static_cast<unsigned int>(nrow))) {
        throw std::runtime_error{std::format("Invalid problem dimension. Given: {}", nrow)};
    }

    auto output = std::vector<double>(ncol);
  std::ignore = get_cec_offset(cec, fn);
    for (auto col{0u}; col < output.size(); ++col) {
        auto sub = std::experimental::submdspan(input, 0, std::experimental::full_extent);
        
        // if constexpr (std::same_as<std::decay_t<decltype(ctx)>, problem_context_view_t>) {
        //     output[col] = evaluate_selected_problem(cec, ctx, fn, sub[col]) + problem_offset;
        // } else {
        //     output[col]
        //         = evaluate_selected_problem(cec, make_problem_context_view(ctx), fn, sub[col]) + problem_offset;
        // }
    }

    return output;
}

} // namespace cecxx::benchmark::detail
