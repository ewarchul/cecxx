#pragma once

#include "cecxx/benchmark/detail/cec2017/problems/basic.hpp"
#include "cecxx/benchmark/detail/problem/hybrid.hpp"

namespace cecxx::benchmark::detail::cec2017 {
const auto hybrid_1 = hybrid_problem{
    std::tuple{zakharov, rosenbrock, rastrigin}, {0.2, 0.4, 0.4}};
const auto hybrid_2 =
    hybrid_problem{std::tuple{ellips, schwefel, bent_cigar}, {0.3, 0.3, 0.4}};
const auto hybrid_3 = hybrid_problem{
    std::tuple{bent_cigar, rosenbrock, bi_rastrigin}, {0.3, 0.3, 0.4}};
const auto hybrid_4 = hybrid_problem{
    std::tuple{ellips, ackley, schaffer, rastrigin}, {0.2, 0.2, 0.2, 0.4}};
const auto hybrid_5 = hybrid_problem{
    std::tuple{bent_cigar, hgbat, rastrigin, rosenbrock}, {0.2, 0.2, 0.3, 0.3}};
const auto hybrid_6 = hybrid_problem{
    std::tuple{escaffer, hgbat, rosenbrock, schwefel}, {0.2, 0.2, 0.3, 0.3}};
const auto hybrid_7 = hybrid_problem{
    std::tuple{katsuura, ackley, grie_rosen, schwefel, rastrigin},
    {0.1, 0.2, 0.2, 0.2, 0.3}};
const auto hybrid_8 =
    hybrid_problem{std::tuple{ellips, ackley, rastrigin, hgbat, discus},
                   {0.2, 0.2, 0.2, 0.2, 0.2}};
const auto hybrid_9 = hybrid_problem{
    std::tuple{bent_cigar, rastrigin, grie_rosen, weierstrass, escaffer},
    {0.2, 0.2, 0.2, 0.2, 0.2}};
const auto hybrid_10 = hybrid_problem{
    std::tuple{hgbat, katsuura, ackley, rastrigin, schwefel, schaffer},
    {0.1, 0.1, 0.2, 0.2, 0.2, 0.2}};
} // namespace cecxx::benchmark::detail::cec2017
