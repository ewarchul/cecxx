#pragma once

#include "cecxx/benchmark/concepts.hpp"
#include "cecxx/benchmark/detail/context.hpp"
#include "cecxx/benchmark/helpers.hpp"
#include "cecxx/benchmark/types.hpp"

#include "cecxx/benchmark/cec_2017/problem_evaluation_mappings.hpp"
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

auto evaluate(cec_edition_t cec, problem_context auto &&ctx, const problem_number_t fn, const auto &input) {
    const auto ncol = input.size();
    const auto nrow = static_cast<dimension_t>(input.at(0).size());

    if (not is_valid_dimension(cec, nrow)) {
        throw std::runtime_error{std::format("Invalid problem dimension. Given: {}", nrow)};
    }

    auto output = std::vector<double>(ncol);
    const auto problem_offset = get_cec_offset(cec, fn);
    for (auto col{0u}; col < output.size(); ++col) {
        if constexpr (std::same_as<std::decay_t<decltype(ctx)>, problem_context_view_t>) {
            output[col] = evaluate_selected_problem(cec, ctx, fn, input.at(col)) + problem_offset;
        } else {
            output[col]
                = evaluate_selected_problem(cec, make_problem_context_view(ctx), fn, input.at(col)) + problem_offset;
        }
    }

    return output;
}

} // namespace cecxx::benchmark::detail
