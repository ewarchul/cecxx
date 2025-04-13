#pragma once

#include <cecxx/benchmark/detail/legacy/functions/multimodal/bi_rastrigin.hpp>
#include <cecxx/benchmark/detail/legacy/functions/multimodal/schaffer.hpp>
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
static constexpr auto basic_1 = detail::basic_problem_invoker{
    cecxx::functions::unimodal::bent_cigar, 1.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_2 = detail::basic_problem_invoker{
    cecxx::functions::unimodal::sum_diff_pow, 1.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_3 = detail::basic_problem_invoker{
    cecxx::functions::unimodal::ellips, 1.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_4 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::discus, 1.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_5 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::zakharov, 1.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_6
    = detail::basic_problem_invoker{cecxx::functions::multimodal::rosenbrock,
                                    2.048 / 100.0,
                                    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_7
    = detail::basic_problem_invoker{cecxx::functions::multimodal::rastrigin,
                                    5.12 / 100.0,
                                    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_8 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::legacy::schaffer, 1.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_9
    = detail::basic_problem_invoker{cecxx::functions::multimodal::legacy::bi_rastrigin,
                                    1.0,
                                    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_10
    = detail::basic_problem_invoker{cecxx::functions::multimodal::step_rastrigin,
                                    5.12 / 100.0,
                                    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_11 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::levy, 1.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};
static constexpr auto basic_12 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::schwefel, 10.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_13 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::ackley, 1.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};
static constexpr auto basic_14 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::hgbat, 5.0 / 100.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_15 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::happycat, 5.0 / 100.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_16 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::escaffer, 1.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};
static constexpr auto basic_17 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::katsuura, 5.0 / 100.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_18
    = detail::basic_problem_invoker{cecxx::functions::multimodal::grie_rosen,
                                    5.0 / 100.0,
                                    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_19
    = detail::basic_problem_invoker{cecxx::functions::multimodal::weierstrass,
                                    0.5 / 100.0,
                                    {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

static constexpr auto basic_20 = detail::basic_problem_invoker{
    cecxx::functions::multimodal::griewank, 6.0, {.rot = do_affine_trans::yes, .shift = do_affine_trans::yes}};

} // namespace cecxx::benchmark::cec_2017
