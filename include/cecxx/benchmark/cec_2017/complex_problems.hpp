#pragma once

#include <cecxx/benchmark/cec_2017/basic_problems.hpp>
#include <cecxx/benchmark/cec_2017/hybrid_problems.hpp>
#include <cecxx/benchmark/detail/problem_invokers/complex_problem_invoker.hpp>

namespace cecxx::benchmark::cec_2017 {

const auto complex_1 = detail::complex_problem_invoker{std::tuple{basic_6, basic_3, basic_7},
                                                       {.deltas = {10.0, 20.0, 30.0},
                                                        .biases = {0.0, 100.0, 200.0},
                                                        .scales = {
                                                            {0, 1},
                                                            {1, 10000 / 1e+10},
                                                            {2, 1},
                                                        }}};

const auto complex_2 = detail::complex_problem_invoker{std::tuple{basic_7, basic_20, basic_12},
                                                       {.deltas = {10.0, 20.0, 30.0},
                                                        .biases = {0.0, 100.0, 200.0},
                                                        .scales = {
                                                            {0, 1.0},
                                                            {1, 10.0},
                                                            {2, 1.0},
                                                        }}};

const auto complex_3 = detail::complex_problem_invoker{std::tuple{basic_6, basic_13, basic_12, basic_7},
                                                       {.deltas = {10.0, 20.0, 30.0, 40.0},
                                                        .biases = {0.0, 100.0, 200.0, 300.0},
                                                        .scales = {
                                                            {0, 1.0},
                                                            {1, 10.0},
                                                            {2, 1.0},
                                                            {3, 1.0},
                                                        }}};

const auto complex_4 = detail::complex_problem_invoker{std::tuple{basic_13, basic_3, basic_20, basic_7},
                                                       {.deltas = {10.0, 20.0, 30.0, 40.0},
                                                        .biases = {0.0, 100.0, 200.0, 300.0},
                                                        .scales = {
                                                            {0, 10.0},
                                                            {1, 1e-6},
                                                            {2, 10.0},
                                                            {3, 1.0},
                                                        }}};

const auto complex_5 = detail::complex_problem_invoker{std::tuple{basic_7, basic_15, basic_13, basic_4, basic_6},
                                                       {.deltas = {10.0, 20.0, 30.0, 40.0, 50.0},
                                                        .biases = {0.0, 100.0, 200.0, 300.0, 400.0},
                                                        .scales = {
                                                            {0, 10.0},
                                                            {1, 1.0},
                                                            {2, 10.0},
                                                            {3, 1e-6},
                                                            {4, 1.0},
                                                        }}};

const auto complex_6 = detail::complex_problem_invoker{std::tuple{basic_16, basic_12, basic_20, basic_6, basic_7},
                                                       {.deltas = {10.0, 20.0, 20.0, 30.0, 40.0},
                                                        .biases = {0.0, 100.0, 200.0, 300.0, 400.0},
                                                        .scales = {
                                                            {0, 1e4 / 2e+7},
                                                            {1, 1},
                                                            {2, 10},
                                                            {3, 1},
                                                            {4, 10},
                                                        }}};

const auto complex_7
    = detail::complex_problem_invoker{std::tuple{basic_14, basic_7, basic_12, basic_1, basic_3, basic_16},
                                      {.deltas = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0},
                                       .biases = {0.0, 100.0, 200.0, 300.0, 400.0, 500.0},
                                       .scales = {
                                           {0, 10},
                                           {1, 10},
                                           {2, 1e4 / 4e3},
                                           {3, 1e4 / 1e30},
                                           {4, 1e4 / 1e10},
                                           {5, 1e4 / 2e7},
                                       }}};

const auto complex_8
    = detail::complex_problem_invoker{std::tuple{basic_13, basic_20, basic_4, basic_6, basic_15, basic_16},
                                      {.deltas = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0},
                                       .biases = {0.0, 100.0, 200.0, 300.0, 400.0, 500.0},
                                       .scales = {
                                           {0, 10},
                                           {1, 10},
                                           {2, 1e4 / 1e10},
                                           {3, 1},
                                           {4, 1},
                                           {5, 1e4 / 2e7},
                                       }}};

const auto complex_9 = detail::complex_problem_invoker{
    std::tuple{hybrid_5, hybrid_6, hybrid_7},
    {.deltas = {10.0, 30.0, 50.0}, .biases = {0.0, 100.0, 200.0}, .scales = {{0, 1}, {1, 1}, {2, 1}}}};

const auto complex_10 = detail::complex_problem_invoker{
    std::tuple{hybrid_5, hybrid_8, hybrid_9},
    {.deltas = {10.0, 30.0, 50.0}, .biases = {0.0, 100.0, 200.0}, .scales = {{0, 1}, {1, 1}, {2, 1}}}};
} // namespace cecxx::benchmark::cec_2017
