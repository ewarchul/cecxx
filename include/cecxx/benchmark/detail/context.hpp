#pragma once

#include <filesystem>
#include <span>
#include <unordered_map>

#include "cecxx/benchmark/detail/types.hpp"
#include "cecxx/benchmark/edition.hpp"
#include "cecxx/types.hpp"

namespace cecxx::benchmark::detail {
template <typename Number>
using context_table_t = std::unordered_map<fn_num, table_data<Number>>;

struct problem_context_view {
  std::span<const f64> shift{};
  std::span<const f64> rotate{};
  std::span<const i64> shuffle{};
};

class context_t {
public:
  context_t(const cec_edition_t edition, const std::filesystem::path &storage,
            const u8 dim);

  auto shift(const u8 fn) const { return shift_.at(fn); }
  auto rotate(const u8 fn) const { return rotate_.at(fn); }
  auto shuffle(const u8 fn) const { return shuffle_.at(fn); }
  auto problem_context(const u8 fn) const {
    return problem_context_view{shift_.at(fn), rotate_.at(fn), shuffle_.at(fn)};
  }

private:
  context_table_t<f64> rotate_{};
  context_table_t<i64> shuffle_{};
  context_table_t<f64> shift_{};
};

} // namespace cecxx::benchmark::detail
