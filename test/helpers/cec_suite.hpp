#pragma once

#include "gtest/gtest.h"
#include "cecxx/evaluator.hpp"

template <cecxx::cec_edition_t Edition, int Dimension> struct CecTestFixture : public testing::Test {
  CecTestFixture() : cec_evaluator{cecxx::evaluator(Edition, Dimension, DATA_STORAGE_PATH)} {}
  cecxx::evaluator cec_evaluator;
};
