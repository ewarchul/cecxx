#pragma once

#include <vector>

#include "cecxx/benchmark/types.hpp"
#include "fuzztest/domain.h"

template <typename T>
auto PositiveVectorOf(auto &&Rng) {
    return fuzztest::ContainerOf<std::vector>(std::forward<decltype(Rng)>(Rng));
}

inline auto InCecProblemRange(cecxx::benchmark::cec_edition_t edition) {
    using namespace cecxx::benchmark;
    switch (edition) {
        case cec_edition_t::cec2017: {
            return fuzztest::Filter([](int x) { return x != 2; }, fuzztest::InRange(1, 30));
        }
    }
}
