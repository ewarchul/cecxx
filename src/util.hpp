#pragma once

#include <stdexcept>
#include <string_view>

#include "cecxx/benchmark/edition.hpp"
#include "cecxx/types.hpp"

namespace cecxx::benchmark::detail {

template <typename T> constexpr auto number_formatter() -> std::string_view {
  if (std::same_as<T, double>) {
    return "%lf";
  } else if (std::same_as<T, i64>) {
    return "%lu";
  }
}

constexpr auto total_problem_num(const cec_edition_t edition) -> i64 {
  switch (edition) {
  case cec_edition_t::cec2017:
    return 30;
  }

  throw std::runtime_error("Unknown CEC edition");
}

} // namespace cecxx::benchmark::detail
