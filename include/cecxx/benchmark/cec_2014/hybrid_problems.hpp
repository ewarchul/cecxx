#pragma once

#include "cecxx/benchmark/detail/problem_invokers/affine_transformations.hpp"
#include "cecxx/functions/multimodal/rastrigin.hpp"
#include "cecxx/functions/unimodal/ellips.hpp"
#include <cecxx/benchmark/cec_2014/basic_problems.hpp>
#include <cecxx/benchmark/detail/problem_invokers/hybrid_problem_invoker.hpp>

namespace cecxx::benchmark::cec_2014 {
const auto hybrid_1 = detail::hybrid_problem_invoker{
    std::tuple{
        cecxx::benchmark::detail::shift{},
        cecxx::benchmark::detail::rotation{},
        cecxx::benchmark::detail::shuffle{},

    },
    std::tuple{
        basic_10, basic_8, basic_1

        // detail::basic_problem_invoker{cecxx::functions::multimodal::schwefel,
        //                               {.rot = do_affine_trans::no, .shift = do_affine_trans::no},
        //                               std::tuple{
        //                                   cecxx::benchmark::detail::scale{1000.0, 100.0},
        //                                   cecxx::benchmark::detail::shift_by_scalar{4.209687462275036e+002},
        //                               }},
        //
        // detail::basic_problem_invoker{cecxx::functions::multimodal::rastrigin,
        //                               {.rot = do_affine_trans::no, .shift = do_affine_trans::no},
        //                               std::tuple{
        //                                   cecxx::benchmark::detail::scale{5.12, 100.0},
        //                               }},
        //
        // detail::basic_problem_invoker{cecxx::functions::unimodal::ellips,
        //                               {.rot = do_affine_trans::no, .shift = do_affine_trans::no},
        //                               std::tuple{}},
    },
    {0.3, 0.3, 0.4}};

const auto hybrid_2 = detail::hybrid_problem_invoker{std::tuple{
                                                         cecxx::benchmark::detail::shift{},
                                                         cecxx::benchmark::detail::rotation{},
                                                         cecxx::benchmark::detail::shuffle{},
                                                     },
                                                     std::tuple{basic_2, basic_14, basic_9},
                                                     {0.3, 0.3, 0.4}};
const auto hybrid_3 = detail::hybrid_problem_invoker{std::tuple{
                                                         cecxx::benchmark::detail::shift{},
                                                         cecxx::benchmark::detail::rotation{},
                                                         cecxx::benchmark::detail::shuffle{},
                                                     },
                                                     std::tuple{basic_7, basic_6, basic_4, basic_16},
                                                     {0.2, 0.2, 0.3, 0.3}};

const auto hybrid_4 = detail::hybrid_problem_invoker{std::tuple{
                                                         cecxx::benchmark::detail::shift{},
                                                         cecxx::benchmark::detail::rotation{},
                                                         cecxx::benchmark::detail::shuffle{},
                                                     },
                                                     std::tuple{basic_14, basic_3, basic_15, basic_9},
                                                     {0.2, 0.2, 0.3, 0.3}};

const auto hybrid_5 = detail::hybrid_problem_invoker{std::tuple{
                                                         cecxx::benchmark::detail::shift{},
                                                         cecxx::benchmark::detail::rotation{},
                                                         cecxx::benchmark::detail::shuffle{},
                                                     },
                                                     std::tuple{basic_16, basic_14, basic_4, basic_10, basic_1},
                                                     {0.1, 0.2, 0.2, 0.2, 0.3}};
const auto hybrid_6 = detail::hybrid_problem_invoker{std::tuple{
                                                         cecxx::benchmark::detail::shift{},
                                                         cecxx::benchmark::detail::rotation{},
                                                         cecxx::benchmark::detail::shuffle{},
                                                     },

                                                     std::tuple{basic_12, basic_13, basic_15, basic_11, basic_5},
                                                     {0.1, 0.2, 0.2, 0.2, 0.3}};
} // namespace cecxx::benchmark::cec_2014
