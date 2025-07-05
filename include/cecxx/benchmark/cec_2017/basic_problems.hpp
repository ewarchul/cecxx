#pragma once

#include "cecxx/functions/multimodal/schaffer.hpp"
#include <cecxx/benchmark/detail/legacy/functions/multimodal/bi_rastrigin.hpp>
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
#include <cecxx/functions/multimodal/schwefel.hpp>
#include <cecxx/functions/multimodal/step_rastrigin.hpp>
#include <cecxx/functions/multimodal/weierstrass.hpp>
#include <cecxx/functions/multimodal/zakharov.hpp>
#include <cecxx/functions/unimodal/bent_cigar.hpp>
#include <cecxx/functions/unimodal/ellips.hpp>
#include <cecxx/functions/unimodal/sum_diff_pow.hpp>

namespace cecxx::benchmark::cec_2017 {
static constexpr auto bent_cigar = detail::basic_problem_invoker{
    cecxx::functions::unimodal::bent_cigar,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto sum_diff_pow = detail::basic_problem_invoker{
    cecxx::functions::unimodal::sum_diff_pow,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto zakharov = detail::basic_problem_invoker{
    cecxx::functions::multimodal::zakharov,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto rosenbrock
    = detail::basic_problem_invoker{cecxx::functions::multimodal::rosenbrock,
                                    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
                                    std::tuple{
                                        cecxx::benchmark::detail::shift{},
                                        cecxx::benchmark::detail::scale{2.048, 100.0},
                                        cecxx::benchmark::detail::rotation{},
                                        detail::shift_by_scalar{1.0},
                                    }};

static constexpr auto rastrigin = detail::basic_problem_invoker{
    cecxx::functions::multimodal::rastrigin,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto schaffer = detail::basic_problem_invoker{
    cecxx::functions::multimodal::schaffer,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{0.5, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto bi_rastrigin = detail::basic_problem_invoker{
    cecxx::functions::multimodal::legacy::bi_rastrigin,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{600.0, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto step_rastrigin
    = detail::basic_problem_invoker{cecxx::functions::multimodal::step_rastrigin,
                                    {.rot = do_affine_trans::no, .shift = do_affine_trans::yes},
                                    std::tuple{
                                        cecxx::benchmark::detail::shift{},
                                        cecxx::benchmark::detail::scale{5.12 / 100.0, 1.0},
                                    }};

static constexpr auto levy = detail::basic_problem_invoker{
    cecxx::functions::multimodal::levy,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{5.12, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto schwefel
    = detail::basic_problem_invoker{cecxx::functions::multimodal::schwefel,
                                    {.rot = do_affine_trans::no, .shift = do_affine_trans::yes},
                                    std::tuple{
                                        cecxx::benchmark::detail::shift{},
                                        cecxx::benchmark::detail::scale{1000.0 / 100.0, 1.0},
                                        cecxx::benchmark::detail::shift_by_scalar{4.209687462275036e+002},
                                    }};
static constexpr auto ellips = detail::basic_problem_invoker{
    cecxx::functions::unimodal::ellips,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto hgbat = detail::basic_problem_invoker{
    cecxx::functions::multimodal::hgbat,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{5.0, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto escaffer = detail::basic_problem_invoker{
    cecxx::functions::multimodal::escaffer,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto katsuura = detail::basic_problem_invoker{
    cecxx::functions::multimodal::katsuura,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{5.0, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto discus = detail::basic_problem_invoker{
    cecxx::functions::multimodal::discus,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};

static constexpr auto weierstrass = detail::basic_problem_invoker{
    cecxx::functions::multimodal::weierstrass,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{0.5, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto happycat = detail::basic_problem_invoker{
    cecxx::functions::multimodal::happycat,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::scale{5.0, 100.0},
               cecxx::benchmark::detail::rotation{}}};

static constexpr auto ackley = detail::basic_problem_invoker{
    cecxx::functions::multimodal::ackley,
    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes},
    std::tuple{cecxx::benchmark::detail::shift{}, cecxx::benchmark::detail::rotation{}}};


} // namespace cecxx::benchmark::cec_2017
