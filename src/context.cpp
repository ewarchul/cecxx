
#include "cecxx/benchmark/detail/context.hpp"

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

context_t::context_t(const cec_edition_t edition, const std::filesystem::path& storage, const int dim) {
  const auto datadir = storage / to_str(edition);
  for (const auto& fn_idx : std::views::iota(1, total_problem_num(edition) + 1)) {
    rotate_[fn_idx] = load_table_data<table_type_t::rotate, double>(datadir, dim, fn_idx);
    shuffle_[fn_idx] = load_table_data<table_type_t::shuffle, int>(datadir, dim, fn_idx);
    shift_[fn_idx] = load_table_data<table_type_t::shift, double>(datadir, dim, fn_idx);
  }
}

}  // namespace cecxx::benchmark::detail
