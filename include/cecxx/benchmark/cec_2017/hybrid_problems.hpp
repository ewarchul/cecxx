#pragma once

#include <cecxx/benchmark/cec_2017/basic_problems.hpp>
#include <cecxx/benchmark/detail/problem_invokers/hybrid_problem_invoker.hpp>

namespace cecxx::benchmark::cec_2017 {

const auto hybrid_1 = detail::hybrid_problem_invoker{std::tuple{
                                                         cecxx::benchmark::detail::shift{},
                                                         cecxx::benchmark::detail::rotation{},
                                                         cecxx::benchmark::detail::shuffle{},

                                                     },
                                                     std::tuple{zakharov, rosenbrock, rastrigin},
                                                     {0.2, 0.4, 0.4}};

const auto hybrid_2 = detail::hybrid_problem_invoker{std::tuple{
                                                         cecxx::benchmark::detail::shift{},
                                                         cecxx::benchmark::detail::rotation{},
                                                         cecxx::benchmark::detail::shuffle{},
                                                     },
                                                     std::tuple{ellips, schwefel, bent_cigar},
                                                     {0.3, 0.3, 0.4}};


const auto hybrid_3 = detail::hybrid_problem_invoker{std::tuple{
                                                         cecxx::benchmark::detail::shift{},
                                                         cecxx::benchmark::detail::rotation{},
                                                         cecxx::benchmark::detail::shuffle{},
                                                     },
                                                     std::tuple{bent_cigar, rosenbrock, bi_rastrigin},
                                                     {0.3, 0.3, 0.4}};

const auto hybrid_4 = detail::hybrid_problem_invoker{std::tuple{
                                                         cecxx::benchmark::detail::shift{},
                                                         cecxx::benchmark::detail::rotation{},
                                                         cecxx::benchmark::detail::shuffle{},
                                                     },
                                                     std::tuple{ellips, ackley, schaffer, rastrigin},
                                                     {0.2, 0.2, 0.2, 0.4}};

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


} // namespace cecxx::benchmark::cec_2017
