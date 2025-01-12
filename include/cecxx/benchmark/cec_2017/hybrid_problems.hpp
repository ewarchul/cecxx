#pragma once

#include <cecxx/benchmark/cec_2017/basic_problems.hpp>
#include <cecxx/benchmark/detail/problem_invokers/hybrid_problem_invoker.hpp>

namespace cecxx::benchmark::cec_2017 {
const auto hybrid_1 = detail::hybrid_problem_invoker{std::tuple{zakharov, rosenbrock, rastrigin}, {0.2, 0.4, 0.4}};
const auto hybrid_2 = detail::hybrid_problem_invoker{std::tuple{ellips, schwefel, bent_cigar}, {0.3, 0.3, 0.4}};
const auto hybrid_3 = detail::hybrid_problem_invoker{std::tuple{bent_cigar, rosenbrock, bi_rastrigin}, {0.3, 0.3, 0.4}};
const auto hybrid_4
    = detail::hybrid_problem_invoker{std::tuple{ellips, ackley, schaffer, rastrigin}, {0.2, 0.2, 0.2, 0.4}};
const auto hybrid_5
    = detail::hybrid_problem_invoker{std::tuple{bent_cigar, hgbat, rastrigin, rosenbrock}, {0.2, 0.2, 0.3, 0.3}};
const auto hybrid_6
    = detail::hybrid_problem_invoker{std::tuple{escaffer, hgbat, rosenbrock, schwefel}, {0.2, 0.2, 0.3, 0.3}};
const auto hybrid_7 = detail::hybrid_problem_invoker{std::tuple{katsuura, ackley, grie_rosen, schwefel, rastrigin},
                                                     {0.1, 0.2, 0.2, 0.2, 0.3}};
const auto hybrid_8
    = detail::hybrid_problem_invoker{std::tuple{ellips, ackley, rastrigin, hgbat, discus}, {0.2, 0.2, 0.2, 0.2, 0.2}};
const auto hybrid_9 = detail::hybrid_problem_invoker{
    std::tuple{bent_cigar, rastrigin, grie_rosen, weierstrass, escaffer}, {0.2, 0.2, 0.2, 0.2, 0.2}};
const auto hybrid_10 = detail::hybrid_problem_invoker{
    std::tuple{hgbat, katsuura, ackley, rastrigin, schwefel, schaffer}, {0.1, 0.1, 0.2, 0.2, 0.2, 0.2}};
} // namespace cecxx::benchmark::cec_2017
