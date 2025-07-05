#pragma once

#include "cecxx/benchmark/detail/problem_invokers/hybrid_problem_invoker.hpp"
#include <cecxx/benchmark/detail/problem_invokers/basic_problem_invoker.hpp>
#include <cecxx/functions/multimodal/ackley.hpp>
#include <cecxx/functions/multimodal/discus.hpp>
#include <cecxx/functions/multimodal/escaffer.hpp>
#include <cecxx/functions/multimodal/grie_rosen.hpp>
#include <cecxx/functions/multimodal/griewank.hpp>
#include <cecxx/functions/multimodal/happycat.hpp>
#include <cecxx/functions/multimodal/hgbat.hpp>
#include <cecxx/functions/multimodal/katsuura.hpp>
#include <cecxx/functions/multimodal/levy.hpp>
#include <cecxx/functions/multimodal/rastrigin.hpp>
#include <cecxx/functions/multimodal/rosenbrock.hpp>
#include <cecxx/functions/multimodal/schaffer.hpp>
#include <cecxx/functions/multimodal/schwefel.hpp>
#include <cecxx/functions/multimodal/weierstrass.hpp>
#include <cecxx/functions/multimodal/zakharov.hpp>
#include <cecxx/functions/unimodal/bent_cigar.hpp>
#include <cecxx/functions/unimodal/ellips.hpp>
#include <cecxx/functions/unimodal/sum_diff_pow.hpp>

namespace cecxx::benchmark::cec_2014 {
static constexpr auto basic_1 = detail::basic_problem_invoker{
    cecxx::functions::unimodal::ellips,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto basic_2 = detail::basic_problem_invoker{
    cecxx::functions::unimodal::bent_cigar,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto basic_3 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::discus,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto basic_4
    = detail::basic_problem_invoker{cecxx::functions::multimodal::rosenbrock,
                                    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                    std::tuple{
                                        cecxx::benchmark::detail::shift{},
                                        cecxx::benchmark::detail::scale{2.048, 100.0},
                                        cecxx::benchmark::detail::rotation{},
                                        detail::shift_by_scalar{1.0},
                                    }};

static constexpr auto basic_5 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::ackley,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto basic_6 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::weierstrass,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{0.5, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto basic_7 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::griewank,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{600.0, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto basic_8
    = detail::basic_problem_invoker{cecxx::functions::multimodal::rastrigin,
                                    {.rot = do_affine_trans::no, .shift = do_affine_trans::yes},
                                    std::tuple{
                                        cecxx::benchmark::detail::shift{},
                                        cecxx::benchmark::detail::scale{5.12 / 100.0, 1.0},
                                    }};

static constexpr auto basic_9 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::rastrigin,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{5.12, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto basic_10
    = detail::basic_problem_invoker{cecxx::functions::multimodal::schwefel,
                                    {.rot = do_affine_trans::no, .shift = do_affine_trans::yes},
                                    std::tuple{
                                        cecxx::benchmark::detail::shift{},
                                        cecxx::benchmark::detail::scale{1000.0 / 100.0, 1.0},
                                        cecxx::benchmark::detail::shift_by_scalar{4.209687462275036e+002},
                                    }};

static constexpr auto basic_11
    = detail::basic_problem_invoker{cecxx::functions::multimodal::schwefel,
                                    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                    std::tuple{
                                        cecxx::benchmark::detail::shift{},
                                        cecxx::benchmark::detail::scale{1000.0, 100.0},
                                        cecxx::benchmark::detail::rotation{},
                                        cecxx::benchmark::detail::shift_by_scalar{4.209687462275036e+002},
                                    }};

static constexpr auto basic_12 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::katsuura,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{5.0, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto basic_13 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::happycat,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{5.0, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto basic_14 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::hgbat,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{5.0, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto basic_15
    = detail::basic_problem_invoker{cecxx::functions::multimodal::grie_rosen,
                                    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                    std::tuple{
                                        cecxx::benchmark::detail::shift{},
                                        cecxx::benchmark::detail::scale{5.0 / 100.0, 1.0},
                                        cecxx::benchmark::detail::rotation{},
                                        cecxx::benchmark::detail::shift_by_scalar{1.0},
                                    }};

static constexpr auto basic_16 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::escaffer,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};
} // namespace cecxx::benchmark::cec_2014
