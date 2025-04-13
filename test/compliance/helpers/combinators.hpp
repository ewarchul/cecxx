#pragma once

#include <vector>

#include "cecxx/benchmark/types.hpp"
#include "fuzztest/fuzztest.h"

template <typename T>
auto PositiveVectorOf(auto &&Rng) {
    return fuzztest::ContainerOf<std::vector>(std::forward<decltype(Rng)>(Rng));
}

inline auto InCecProblemRange(cecxx::benchmark::cec_edition_t edition) {
    using namespace cecxx::benchmark;
    using enum cec_edition_t;
    switch (edition) {
        case cec2014:
            return fuzztest::Filter([](int x) { return x != 31; }, fuzztest::InRange(1, 30));
        case cec2017: {
            return fuzztest::Filter([](int x) { return x != 2; }, fuzztest::InRange(1, 30));
        }
    }
}
