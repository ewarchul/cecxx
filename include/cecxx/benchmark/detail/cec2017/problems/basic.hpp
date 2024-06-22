#pragma once

#include "cecxx/benchmark/detail/legacy/functions/multimodal/bi_rastrigin.hpp"
#include "cecxx/benchmark/detail/legacy/functions/multimodal/schaffer.hpp"
#include "cecxx/benchmark/detail/problem/basic.hpp"
#include "cecxx/functions/multimodal/ackley.hpp"
#include "cecxx/functions/multimodal/discus.hpp"
#include "cecxx/functions/multimodal/escaffer.hpp"
#include "cecxx/functions/multimodal/grie_rosen.hpp"
#include "cecxx/functions/multimodal/griewank.hpp"
#include "cecxx/functions/multimodal/happycat.hpp"
#include "cecxx/functions/multimodal/hgbat.hpp"
#include "cecxx/functions/multimodal/katsuura.hpp"
#include "cecxx/functions/multimodal/levy.hpp"
#include "cecxx/functions/multimodal/rastrigin.hpp"
#include "cecxx/functions/multimodal/rosenbrock.hpp"
#include "cecxx/functions/multimodal/schwefel.hpp"
#include "cecxx/functions/multimodal/step_rastrigin.hpp"
#include "cecxx/functions/multimodal/weierstrass.hpp"
#include "cecxx/functions/multimodal/zakharov.hpp"
#include "cecxx/functions/unimodal/bent_cigar.hpp"
#include "cecxx/functions/unimodal/ellips.hpp"
#include "cecxx/functions/unimodal/sum_diff_pow.hpp"

namespace cecxx::benchmark::detail::cec2017 {
static constexpr auto sum_diff_pow = basic_problem{cecxx::functions::unimodal::sum_diff_pow};
static constexpr auto bent_cigar = basic_problem{cecxx::functions::unimodal::bent_cigar};
static constexpr auto ellips = basic_problem{cecxx::functions::unimodal::ellips};
static constexpr auto discus = basic_problem{cecxx::functions::multimodal::discus};
static constexpr auto zakharov = basic_problem{cecxx::functions::multimodal::zakharov};
static constexpr auto rosenbrock = basic_problem{cecxx::functions::multimodal::rosenbrock, 2.048 / 100.0};
static constexpr auto rastrigin = basic_problem{cecxx::functions::multimodal::rastrigin, 5.12 / 100.0};
static constexpr auto schaffer = basic_problem{cecxx::functions::multimodal::legacy::schaffer};
static constexpr auto bi_rastrigin = basic_problem{cecxx::functions::multimodal::legacy::bi_rastrigin};
static constexpr auto step_rastrigin = basic_problem{cecxx::functions::multimodal::step_rastrigin, 5.12 / 100.0};
static constexpr auto levy = basic_problem{cecxx::functions::multimodal::levy};
static constexpr auto schwefel = basic_problem{cecxx::functions::multimodal::schwefel, 10.0};
static constexpr auto ackley = basic_problem{cecxx::functions::multimodal::ackley};
static constexpr auto hgbat = basic_problem{cecxx::functions::multimodal::hgbat, 5.0 / 100.0};
static constexpr auto happycat = basic_problem{cecxx::functions::multimodal::happycat, 5.0 / 100.0};
static constexpr auto escaffer = basic_problem{cecxx::functions::multimodal::escaffer};
static constexpr auto katsuura = basic_problem{cecxx::functions::multimodal::katsuura, 5.0 / 100.0};
static constexpr auto grie_rosen = basic_problem{cecxx::functions::multimodal::grie_rosen, 5.0 / 100.0};
static constexpr auto weierstrass = basic_problem{cecxx::functions::multimodal::weierstrass, 0.5 / 100.0};
static constexpr auto griewank = basic_problem{cecxx::functions::multimodal::griewank, 6.0};
}  // namespace cecxx::benchmark::detail::cec2017
