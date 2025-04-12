#pragma once

#include <cecxx/benchmark/cec_2017/basic_problems.hpp>
#include <cecxx/benchmark/detail/problem_invokers/hybrid_problem_invoker.hpp>

namespace cecxx::benchmark::cec_2017 {
const auto hybrid_1 = detail::hybrid_problem_invoker{std::tuple{basic_5, basic_6, basic_7}, {0.2, 0.4, 0.4}};
const auto hybrid_2 = detail::hybrid_problem_invoker{std::tuple{basic_3, basic_12, basic_2}, {0.3, 0.3, 0.4}};
const auto hybrid_3 = detail::hybrid_problem_invoker{std::tuple{basic_2, basic_6, basic_9}, {0.3, 0.3, 0.4}};
const auto hybrid_4
    = detail::hybrid_problem_invoker{std::tuple{basic_3, basic_13, basic_8, basic_7}, {0.2, 0.2, 0.2, 0.4}};
const auto hybrid_5
    = detail::hybrid_problem_invoker{std::tuple{basic_2, basic_14, basic_7, basic_6}, {0.2, 0.2, 0.3, 0.3}};
const auto hybrid_6
    = detail::hybrid_problem_invoker{std::tuple{basic_16, basic_14, basic_6, basic_12}, {0.2, 0.2, 0.3, 0.3}};
const auto hybrid_7 = detail::hybrid_problem_invoker{std::tuple{basic_17, basic_13, basic_18, basic_12, basic_7},
                                                     {0.1, 0.2, 0.2, 0.2, 0.3}};
const auto hybrid_8 = detail::hybrid_problem_invoker{std::tuple{basic_3, basic_13, basic_7, basic_14, basic_4},
                                                     {0.2, 0.2, 0.2, 0.2, 0.2}};
const auto hybrid_9 = detail::hybrid_problem_invoker{std::tuple{basic_2, basic_7, basic_18, basic_12, basic_16},
                                                     {0.2, 0.2, 0.2, 0.2, 0.2}};
const auto hybrid_10 = detail::hybrid_problem_invoker{
    std::tuple{basic_14, basic_17, basic_13, basic_7, basic_12, basic_8}, {0.1, 0.1, 0.2, 0.2, 0.2, 0.2}};
} // namespace cecxx::benchmark::cec_2017
