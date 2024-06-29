#pragma once

#include <cmath>
#include <vector>

#include "cecxx/benchmark/detail/context.hpp"
#include "cecxx/benchmark/detail/legacy/affine_transformation.hpp"

namespace cecxx::functions::multimodal::legacy {
inline auto schaffer(std::span<const f64> input,
                     benchmark::detail::problem_context_view ctx,
                     benchmark::detail::affine_mask_t mask,
                     std::vector<f64> acc = {}) -> f64 {
  const auto nrow = input.size();
  std::vector<f64> ys{};
  if (acc.empty()) {
    ys.resize(nrow);
  } else {
    ys = acc;
  }
  auto z = std::vector<f64>(nrow);

  auto output{0.0};
  sr_func(input, z, ctx.shift, ctx.rotate, 1.0, mask.shift, mask.rot, ys);
  f64 tmp{};
  for (auto i = 0u; i < nrow - 1; ++i) {
    z[i] = std::pow(ys[i] * ys[i] + ys[i + 1] * ys[i + 1], 0.5);
    tmp = std::sin(50.0 * std::pow(z[i], 0.2));
    output += std::pow(z[i], 0.5) + std::pow(z[i], 0.5) * tmp * tmp;
  }

  return output * output / (static_cast<f64>(nrow) - 1) /
         (static_cast<f64>(nrow) - 1);
}

} // namespace cecxx::functions::multimodal::legacy
