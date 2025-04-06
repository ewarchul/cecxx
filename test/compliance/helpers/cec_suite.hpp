#pragma once

// clang-format off
#include "gtest/gtest.h"
// clang-format on

#include "cecxx/benchmark/evaluator.hpp"
#include "cecxx/benchmark/types.hpp"

template <cecxx::benchmark::cec_edition_t Edition, std::size_t... Dimension>
struct CecTestFixture : public testing::Test {
    CecTestFixture()
        : cec_evaluator{cecxx::benchmark::evaluator(Edition, std::vector{Dimension...}, DATA_STORAGE_PATH)} {}
    cecxx::benchmark::evaluator cec_evaluator;
};
