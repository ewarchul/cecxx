#pragma once

#include <cecxx/benchmark/cec_2013/basic_problems.hpp>
#include <cecxx/benchmark/detail/problem_invokers/complex_problem_invoker.hpp>

namespace cecxx::benchmark::cec_2013 {

const auto complex_1 = detail::complex_problem_invoker{std::tuple{basic_6, basic_5, basic_3, basic_4, basic_1},
                                                       {.deltas = {10, 20, 30, 40, 50},
                                                        .biases = {0, 100, 200, 300, 400},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::no, .shift = do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {0, 1.0},
                                                            {1, 0.000001},
                                                            {2, 10000.0 / 1e+30},
                                                            {3, 0.000001},
                                                            {4, 10000 / 1e+5},
                                                        }}};

const auto complex_2 = detail::complex_problem_invoker{std::tuple{basic_15, basic_15, basic_15},
                                                       {.deltas = {20, 20, 20},
                                                        .biases = {0, 100, 200},
                                                        .masks = {
                                                          {.rot = do_affine_trans::no, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::no, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::no, .shift =
                                                          do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {0, 1.0},
                                                            {1, 1.0},
                                                            {2, 1.0},
                                                        }}};

const auto complex_3 = detail::complex_problem_invoker{std::tuple{basic_15, basic_15, basic_15},
                                                       {.deltas = {20, 20, 20},
                                                        .biases = {0, 100, 200},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {0, 1.0},
                                                            {1, 1.0},
                                                            {2, 1.0},
                                                        }}};

const auto complex_4 = detail::complex_problem_invoker{std::tuple{basic_15, basic_12, basic_9},
                                                       {.deltas = {20, 20, 20},
                                                        .biases = {0, 100, 200},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {0, 1000.0 / 4e+3},
                                                            {1, 1000.0 / 1e+3},
                                                            {2, 1000.0 / 400.0},
                                                        }}};

const auto complex_5 = detail::complex_problem_invoker{std::tuple{basic_15, basic_12, basic_9},
                                                       {.deltas = {10.0, 30.0, 50.0},
                                                        .biases = {0, 100, 200},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {0, 1000 / 4e+3},
                                                            {1, 1000 / 1e+3},
                                                            {2, 1000.0 / 400.0},
                                                        }}};

const auto complex_6 = detail::complex_problem_invoker{std::tuple{basic_15, basic_12, basic_2, basic_9, basic_10},
                                                       {.deltas = {10,10,10,10,10},
                                                        .biases = {0, 100, 200, 300, 400},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {0, 1000.0 / 4e+3},
                                                            {1, 1000.0 / 1000.0},
                                                            {2, 1000.0 / 1e+10},
                                                            {3, 1000.0 / 400.0},
                                                            {4, 10.0},
                                                        }}};

const auto complex_7 = detail::complex_problem_invoker{std::tuple{basic_10, basic_12, basic_15, basic_9, basic_1},
                                                       {.deltas = {10,10,10,20,20},
                                                        .biases = {0, 100, 200, 300, 400},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::no, .shift =
                                                          do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {0, 10000.0 / 100.0},
                                                            {1, 10000.0 / 1e+3},
                                                            {2, 10000.0 / 4e+3},
                                                            {3, 10000.0 / 400.0},
                                                            {4, 10000.0 / 1e+5},
                                                        }}};

const auto complex_8 = detail::complex_problem_invoker{std::tuple{basic_19, basic_7, basic_15, basic_20, basic_1},
                                                       {.deltas = {10, 20, 30, 40, 50},
                                                        .biases = {0, 100, 200, 300, 400},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift =
                                                          do_affine_trans::yes},
                                                          {.rot = do_affine_trans::no, .shift =
                                                          do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {0, 10000.0 / 4e+3},
                                                            {1, 10000.0 / 4e+6},
                                                            {2, 10000.0 / 4e+3},
                                                            {3, 10000.0 / 2e+7},
                                                            {4, 10000.0 / 1e+5},
                                                        }}};

} // namespace cecxx::benchmark::cec_2013
