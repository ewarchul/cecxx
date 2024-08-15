
#include "cecxx/benchmark/detail/context.hpp"

#include <algorithm>
#include <ranges>

#include "cecxx/benchmark/edition.hpp"
#include "table_io.hpp"
#include "util.hpp"

namespace cecxx::benchmark::detail {

namespace {
inline auto to_str(const cec_edition_t edition) -> std::string_view {
  switch (edition) {
    case cec_edition_t::cec2017:
      return "cec2017";
  }

  throw std::runtime_error{"Unknown CEC edition"};
}
}  // namespace

context_t::context_t(const cec_edition_t edition, const std::filesystem::path &storage,
                     std::span<const usize> dims) {
  const auto datadir = storage / to_str(edition);
  std::ranges::for_each(dims.begin(), dims.end(), [&](const auto dim) {
    for (const auto &fn : std::views::iota(1, total_problem_num(edition) + 1)) {
      auto fn_idx = static_cast<usize>(fn);
      rotate_[dim].insert(
          {fn_idx, load_table_data<table_type_t::rotate, f64>(datadir, dim, fn_idx)});
      shuffle_[dim].insert(
          {fn_idx, load_table_data<table_type_t::shuffle, i64>(datadir, dim, fn_idx)});
      shift_[dim].insert({fn_idx, load_table_data<table_type_t::shift, f64>(datadir, dim, fn_idx)});
    }
  });
}

}  // namespace cecxx::benchmark::detail
