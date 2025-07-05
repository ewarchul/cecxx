#pragma once

#include <cecxx/benchmark/cec_2014/basic_problems.hpp>
#include <cecxx/benchmark/cec_2014/hybrid_problems.hpp>
#include <cecxx/benchmark/detail/problem_invokers/complex_problem_invoker.hpp>

namespace cecxx::benchmark::cec_2014 {

const auto complex_1 = detail::complex_problem_invoker{std::tuple{basic_4, basic_1, basic_2, basic_3, basic_1},
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
                                                            {10000, 1e+4},
                                                            {10000, 1e+10},
                                                            { 10000, 1e+30},
                                                            {10000, 1e+10},
                                                            {10000, 1e+10},
                                                        }}};

const auto complex_2 = detail::complex_problem_invoker{std::tuple{basic_11, basic_9, basic_14},
                                                       {.deltas = {20, 20, 20},
                                                        .biases = {0, 100, 200},
                                                        .masks = {
                                                          {.rot = do_affine_trans::no, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {1.0, 1.0},
                                                            {1.0, 1.0},
                                                            {1.0, 1.0},
                                                        }}};

const auto complex_3 = detail::complex_problem_invoker{std::tuple{basic_11, basic_9, basic_1},
                                                       {.deltas = {10, 30, 50},
                                                        .biases = {0, 100, 200},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {1000.0, 4e+3},
                                                            { 1000.0, 1e+3},
                                                            { 1000.0, 1e+10},
                                                        }}};

const auto complex_4 = detail::complex_problem_invoker{std::tuple{basic_11, basic_13, basic_1, basic_6, basic_7},
                                                       {.deltas = {10, 10, 10, 10, 10},
                                                        .biases = {0, 100, 200, 300, 400},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {1000.0,  4e+3},
                                                            {1000.0,  1e+3},
                                                            {1000.0,  1e+10},
                                                            {1000.0,  400.0},
                                                            {1000.0,  100.0},
                                                        }}};

const auto complex_5 = detail::complex_problem_invoker{std::tuple{basic_14, basic_9, basic_11, basic_6, basic_1},
                                                       {.deltas = {10, 10, 10, 20, 20},
                                                        .biases = {0, 100, 200, 300, 400},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            { 10000.0 , 1e+3},
                                                            { 10000.0 , 1e+3},
                                                            { 10000.0 , 4e+3},
                                                            { 10000.0 , 400},
                                                            { 10000.0 , 1e+10},
                                                        }}};

const auto complex_6 = detail::complex_problem_invoker{std::tuple{basic_15, basic_13, basic_11, basic_16, basic_1},
                                                       {.deltas = {10, 20, 30, 40, 50},
                                                        .biases = {0, 100, 200, 300, 400},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            { 10000.0,  4e+3},
                                                            { 10000.0,  1e+3},
                                                            { 10000.0,  4e+3},
                                                            { 10000.0,  2e+7},
                                                            { 10000.0,  1e+10},
                                                        }}};

const auto complex_7 = detail::complex_problem_invoker{std::tuple{hybrid_1, hybrid_2, hybrid_3},
                                                       {.deltas = {10, 30, 50},
                                                        .biases = {0, 100, 200},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {1.0, 1.0},
                                                            {1.0, 1.0},
                                                            {1.0, 1.0},

                                                        }}};

const auto complex_8 = detail::complex_problem_invoker{std::tuple{hybrid_4, hybrid_5, hybrid_6},
                                                       {.deltas = {10, 30, 50},
                                                        .biases = {0, 100, 200},
                                                        .masks = {
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                          {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                                        },
                                                        .scales = {
                                                            {1.0, 1.0},
                                                            {1.0, 1.0},
                                                            {1.0, 1.0},
                                                        }}};

} // namespace cecxx::benchmark::cec_2014
