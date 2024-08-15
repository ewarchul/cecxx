#pragma once

#include <filesystem>
#include <span>
#include <unordered_map>

#include "cecxx/benchmark/detail/types.hpp"
#include "cecxx/benchmark/edition.hpp"
#include "cecxx/types.hpp"

namespace cecxx::benchmark::detail {
using fn_num = usize;
template <typename Number>
using geom_transfrom_fn_grid = std::unordered_map<fn_num, table_data<Number>>;

using dimension = usize;
template <typename Number>
using geom_transform_dim_fn_grid = std::unordered_map<dimension, geom_transfrom_fn_grid<Number>>;

struct problem_context_view {
  std::span<const f64> shift{};
  std::span<const f64> rotate{};
  std::span<const i64> shuffle{};
};

class context_t {
 public:
  context_t(const cec_edition_t edition, const std::filesystem::path &storage,
            std::span<const usize> dims);

  auto shift(const usize fn, const usize dim) const { return shift_.at(dim).at(fn); }
  auto rotate(const usize fn, const usize dim) const { return rotate_.at(dim).at(fn); }
  auto shuffle(const usize fn, const usize dim) const { return shuffle_.at(dim).at(fn); }
  auto problem_context(const usize fn, const usize dim) const {
    return problem_context_view{.shift = shift_.at(dim).at(fn),
                                .rotate = rotate_.at(dim).at(fn),
                                .shuffle = shuffle_.at(dim).at(fn)};
  }

 private:
  geom_transform_dim_fn_grid<f64> rotate_{};
  geom_transform_dim_fn_grid<i64> shuffle_{};
  geom_transform_dim_fn_grid<f64> shift_{};
};

}  // namespace cecxx::benchmark::detail
