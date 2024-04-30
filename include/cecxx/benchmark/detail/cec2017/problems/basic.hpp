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
const auto sum_diff_pow = basic_problem{cecxx::functions::unimodal::sum_diff_pow};
const auto bent_cigar = basic_problem{cecxx::functions::unimodal::bent_cigar};
const auto ellips = basic_problem{cecxx::functions::unimodal::ellips};

const auto discus = basic_problem{cecxx::functions::multimodal::discus};
const auto zakharov = basic_problem{cecxx::functions::multimodal::zakharov};
const auto rosenbrock = basic_problem{cecxx::functions::multimodal::rosenbrock, 2.048 / 100.0};
const auto rastrigin = basic_problem{cecxx::functions::multimodal::rastrigin, 5.12 / 100.0};
const auto schaffer = basic_problem{cecxx::functions::multimodal::legacy::schaffer};
const auto bi_rastrigin = basic_problem{cecxx::functions::multimodal::legacy::bi_rastrigin};
const auto step_rastrigin = basic_problem{cecxx::functions::multimodal::step_rastrigin, 5.12 / 100.0};
const auto levy = basic_problem{cecxx::functions::multimodal::levy};
const auto schwefel = basic_problem{cecxx::functions::multimodal::schwefel, 10.0};
const auto ackley = basic_problem{cecxx::functions::multimodal::ackley};
const auto hgbat = basic_problem{cecxx::functions::multimodal::hgbat, 5.0 / 100.0};
const auto happycat = basic_problem{cecxx::functions::multimodal::happycat, 5.0 / 100.0};
const auto escaffer = basic_problem{cecxx::functions::multimodal::escaffer};
const auto katsuura = basic_problem{cecxx::functions::multimodal::katsuura, 5.0 / 100.0};
const auto grie_rosen = basic_problem{cecxx::functions::multimodal::grie_rosen, 5.0 / 100.0};
const auto weierstrass = basic_problem{cecxx::functions::multimodal::weierstrass, 0.5 / 100.0};
const auto griewank = basic_problem{cecxx::functions::multimodal::griewank, 6.0};
}  // namespace cecxx::benchmark::detail::cec2017
