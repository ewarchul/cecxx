// clang-format off
#include "gtest/gtest.h"
#include "fuzztest/fuzztest.h"
#include "fuzztest/googletest_fixture_adapter.h"
#include "fuzztest/domain.h"
// clang-format on

#include <range/v3/all.hpp>

#include "cecxx/benchmark/evaluator.hpp"

#include "helpers/combinators.hpp"

#include "helpers/cec_suite.hpp"
#include "helpers/oracle.hpp"

using namespace fuzztest;
using namespace cecxx::benchmark;

constexpr auto MAX_ABS_ERROR = 1e-8;

constexpr auto CEC_2017_LOWER_BOUND = -100.0;
constexpr auto CEC_2017_UPPER_BOUND = 100.0;

class Cec2017ConformanceTest
    : public PerFuzzTestFixtureAdapter<
          CecTestFixture<cec_edition_t::cec2017, 10, 30, 50, 100>> {
public:
  void Cec2017D10ImplsAreEquiv(std::vector<double> input, int problem_num) {
    Cec2017ImplsAreEquivImpl(input, problem_num);
  }

  void Cec2017D30ImplsAreEquiv(std::vector<double> input, int problem_num) {
    Cec2017ImplsAreEquivImpl(input, problem_num);
  }

  void Cec2017D50ImplsAreEquiv(std::vector<double> input, int problem_num) {
    Cec2017ImplsAreEquivImpl(input, problem_num);
  }

  void Cec2017D100ImplsAreEquiv(std::vector<double> input, int problem_num) {
    Cec2017ImplsAreEquivImpl(input, problem_num);
  }

private:
  void Cec2017ImplsAreEquivImpl(std::vector<double> input, int problem_num) {
    const auto oracle_output = calculate_oracle_output(input, problem_num);
    const auto cecxx_output =
        cec_evaluator(problem_num, std::vector<std::vector<double>>{input});
    EXPECT_NEAR(oracle_output, cecxx_output[0], MAX_ABS_ERROR);
  }
};

FUZZ_TEST_F(Cec2017ConformanceTest, Cec2017D10ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2017_LOWER_BOUND,
                                                  CEC_2017_UPPER_BOUND))
                     .WithSize(10),
                 InCecProblemRange(cec_edition_t::cec2017));

FUZZ_TEST_F(Cec2017ConformanceTest, Cec2017D30ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2017_LOWER_BOUND,
                                                  CEC_2017_UPPER_BOUND))
                     .WithSize(30),
                 InCecProblemRange(cec_edition_t::cec2017));

FUZZ_TEST_F(Cec2017ConformanceTest, Cec2017D50ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2017_LOWER_BOUND,
                                                  CEC_2017_UPPER_BOUND))
                     .WithSize(50),
                 InCecProblemRange(cec_edition_t::cec2017));

FUZZ_TEST_F(Cec2017ConformanceTest, Cec2017D100ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2017_LOWER_BOUND,
                                                  CEC_2017_UPPER_BOUND))
                     .WithSize(100),
                 InCecProblemRange(cec_edition_t::cec2017));
