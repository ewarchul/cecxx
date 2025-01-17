#pragma once

#include <cecxx/benchmark/concepts.hpp>
#include <cecxx/benchmark/detail/context.hpp>
#include <cecxx/benchmark/helpers.hpp>
#include <cecxx/benchmark/types.hpp>

#include <concepts>
#include <ranges>
#include <type_traits>

namespace cecxx::benchmark::detail {

auto evaluate_selected_problem(cec_edition_t cec, problem_context_view_t ctx, const problem_number_t fn,
                               std::span<const double> input) -> double;

auto evaluate(cec_edition_t cec, problem_context auto &&ctx, const problem_number_t fn, matrix_t input) {
    const auto nrow = input.extent(0);
    const auto ncol = input.extent(1);

    if (not is_valid_dimension(cec, static_cast<unsigned int>(nrow))) {
        throw std::runtime_error{std::format("Invalid problem dimension. Given: {}", nrow)};
    }

    auto output = std::vector<double>(ncol);
    const auto problem_offset = get_cec_offset(cec, fn);
    for (auto c : std::ranges::views::iota(0uz, ncol)) {
        auto col = std::experimental::submdspan(input, std::experimental::full_extent, c);
        auto col_view = std::span{col.data_handle(), col.size()};
        if constexpr (std::same_as<std::decay_t<decltype(ctx)>, problem_context_view_t>) {
            output[c] = evaluate_selected_problem(cec, ctx, fn, col_view) + problem_offset;
        } else {
            output[c] = evaluate_selected_problem(cec, make_problem_context_view(ctx), fn, col_view) + problem_offset;
        }
    }

    return output;
}

} // namespace cecxx::benchmark::detail
