// clang-format off
#include "gtest/gtest.h"
#include "fuzztest/fuzztest.h"
#include "fuzztest/googletest_fixture_adapter.h"
#include "fuzztest/domain.h"
// clang-format on

#include <range/v3/all.hpp>

#include "cecxx/benchmark/evaluator.hpp"

#include "cecxx/types.hpp"
#include "helpers/combinators.hpp"

#include "helpers/cec_suite.hpp"
#include "helpers/oracle.hpp"

using namespace fuzztest;
using namespace cecxx::benchmark;

constexpr auto MAX_ABS_ERROR = 1e-10;

class CecFuzzTest10D : public PerFuzzTestFixtureAdapter<
                           CecTestFixture<cec_edition_t::cec2017, 10>> {
public:
  void Cec2017ImplsAreEquiv(std::vector<double> input, int problem_num) {
    const auto oracle_output = calculate_oracle_output(input, problem_num);
    const auto cecxx_output =
        cec_evaluator(problem_num, std::vector<std::vector<double>>{input});
    EXPECT_NEAR(oracle_output, cecxx_output[0], MAX_ABS_ERROR);
  }
};

FUZZ_TEST_F(CecFuzzTest10D, Cec2017ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(-1.0, 1.0)).WithSize(10),
                 InCecProblemRange(cec_edition_t::cec2017));

class CecFuzzTest30D : public PerFuzzTestFixtureAdapter<
                           CecTestFixture<cec_edition_t::cec2017, 30>> {
public:
  void Cec2017ImplsAreEquiv(std::vector<double> input, int problem_num) {
    const auto oracle_output = calculate_oracle_output(input, problem_num);
    const auto cecxx_output =
        cec_evaluator(problem_num, std::vector<std::vector<double>>{input});
    EXPECT_NEAR(oracle_output, cecxx_output[0], MAX_ABS_ERROR);
  }
};

FUZZ_TEST_F(CecFuzzTest30D, Cec2017ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(-1.0, 1.0)).WithSize(30),
                 InCecProblemRange(cec_edition_t::cec2017));

class CecFuzzTest50D : public PerFuzzTestFixtureAdapter<
                           CecTestFixture<cec_edition_t::cec2017, 50>> {
public:
  void Cec2017ImplsAreEquiv(std::vector<double> input, int problem_num) {
    const auto oracle_output = calculate_oracle_output(input, problem_num);
    const auto cecxx_output =
        cec_evaluator(problem_num, std::vector<std::vector<double>>{input});

    EXPECT_NEAR(oracle_output, cecxx_output[0], MAX_ABS_ERROR);
  }
};

FUZZ_TEST_F(CecFuzzTest50D, Cec2017ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(-1.0, 1.0)).WithSize(50),
                 InCecProblemRange(cec_edition_t::cec2017));

class CecFuzzTest100D : public PerFuzzTestFixtureAdapter<
                            CecTestFixture<cec_edition_t::cec2017, 100>> {
public:
  void Cec2017ImplsAreEquiv(std::vector<double> input, int problem_num) {
    const auto oracle_output = calculate_oracle_output(input, problem_num);
    const auto cecxx_output =
        cec_evaluator(problem_num, std::vector<std::vector<double>>{input});
    EXPECT_NEAR(oracle_output, cecxx_output[0], MAX_ABS_ERROR);
  }
};

FUZZ_TEST_F(CecFuzzTest100D, Cec2017ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(-1.0, 1.0)).WithSize(100),
                 InCecProblemRange(cec_edition_t::cec2017));
