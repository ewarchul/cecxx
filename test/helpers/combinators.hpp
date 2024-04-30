#pragma once

#include <vector>

#include "cecxx/types.hpp"
#include "fuzztest/domain.h"

template <typename T> auto PositiveVectorOf(auto&& Rng) {
  return fuzztest::ContainerOf<std::vector>(std::forward<decltype(Rng)>(Rng));
}

auto InCecProblemRange(cecxx::cec_edition_t edition) {
  switch (edition) {
  case cecxx::cec_edition_t::cec2017: {
    return fuzztest::Filter([](int x) { return x != 2; }, fuzztest::InRange(1, 28));
  }
  }
}
