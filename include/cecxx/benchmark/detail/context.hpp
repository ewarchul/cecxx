#pragma once

#include <filesystem>
#include <span>
#include <unordered_map>

#include "cecxx/benchmark/detail/types.hpp"
#include "cecxx/benchmark/edition.hpp"

namespace cecxx::benchmark::detail {
template <typename Number> using context_table_t = std::unordered_map<fn_num, table_data<Number>>;

struct problem_context_view {
  std::span<const double> shift{};
  std::span<const double> rotate{};
  std::span<const int> shuffle{};
};

class context_t {
 public:
  context_t(const cec_edition_t edition, const std::filesystem::path& storage, const int dim);

  auto shift(const int fn) const { return shift_.at(fn); }
  auto rotate(const int fn) const { return rotate_.at(fn); }
  auto shuffle(const int fn) const { return shuffle_.at(fn); }
  auto problem_context(const int fn) const {
    return problem_context_view{shift_.at(fn), rotate_.at(fn), shuffle_.at(fn)};
  }

 private:
  context_table_t<double> rotate_{};
  context_table_t<int> shuffle_{};
  context_table_t<double> shift_{};
};

}  // namespace cecxx::benchmark::detail
