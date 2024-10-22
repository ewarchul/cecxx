#pragma once

#include <cmath>
#include <vector>

#include "cecxx/benchmark/detail/context.hpp"
#include "cecxx/benchmark/detail/legacy/affine_transformation.hpp"

namespace cecxx::functions::multimodal::legacy {

inline auto bi_rastrigin(std::span<const f64> input, benchmark::detail::problem_context_view ctx,
                         benchmark::detail::affine_mask_t mask) -> f64 {
  using namespace cecxx::benchmark;
  const auto nrow = input.size();
  auto y = std::vector<f64>(nrow);
  auto z = std::vector<f64>(nrow);
  auto tmpx = std::vector<f64>(nrow);

  if (to_underlying(mask.shift) == 1) {
    detail::shiftfunc(input, y, ctx.shift);
  } else {
    // shrink to the orginal search range
    for (auto i = 0u; i < nrow; i++) {
      y[i] = input[i];
    }
  }

  // shrink to the orginal search range
  for (auto i = 0u; i < nrow; i++) {
    y[i] *= 10.0 / 100.0;
  }

  constexpr auto mu0 = 2.5;

  for (auto i = 0u; i < nrow; i++) {
    tmpx[i] = 2 * y[i];
    if (ctx.shift[i] < 0.0) tmpx[i] *= -1.;
  }
  for (auto i = 0u; i < nrow; i++) {
    z[i] = tmpx[i];
    tmpx[i] += mu0;
  }

  f64 tmp{};
  f64 tmp1{};
  f64 tmp2{};
  constexpr auto d = 1.0;
  auto s = 1.0 - 1.0 / (2.0 * std::pow(static_cast<f64>(nrow) + 20.0, 0.5) - 8.2);
  auto mu1 = -std::pow((mu0 * mu0 - d) / s, 0.5);
  for (auto i = 0u; i < nrow; i++) {
    tmp = tmpx[i] - mu0;
    tmp1 += tmp * tmp;
    tmp = tmpx[i] - mu1;
    tmp2 += tmp * tmp;
  }
  tmp2 *= s;
  tmp2 += d * static_cast<f64>(nrow);
  tmp = 0.0;
  auto output{0.0};

  if (to_underlying(mask.rot) == 1) {
    detail::rotatefunc(z, y, ctx.rotate);
    for (auto i = 0u; i < nrow; i++) {
      tmp += std::cos(2.0 * M_PI * y[i]);
    }
    if (tmp1 < tmp2) {
      output = tmp1;
    } else {
      output = tmp2;
    }
    output += 10.0 * (static_cast<f64>(nrow) - tmp);
  } else {
    for (auto i = 0u; i < nrow; i++) {
      tmp += std::cos(2.0 * M_PI * z[i]);
    }
    if (tmp1 < tmp2) {
      output = tmp1;
    } else {
      output = tmp2;
    }
    output += 10.0 * (static_cast<f64>(nrow) - tmp);
  }

  return output;
}

}  // namespace cecxx::functions::multimodal::legacy
