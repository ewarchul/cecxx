// clang-format off
#include "gtest/gtest.h"
#include "cecxx/mdspan.hpp"
#include "fuzztest/fuzztest.h"
#include "fuzztest/googletest_fixture_adapter.h"
#include "fuzztest/domain.h"
// clang-format on

#include "cecxx/benchmark/evaluator.hpp"

#include "helpers/combinators.hpp"

#include "helpers/cec_suite.hpp"
#include "helpers/oracle.hpp"
#include "oracle/cec2014.h"

using namespace fuzztest;
using namespace cecxx::benchmark;

constexpr auto MAX_ABS_ERROR = 1e-7;

constexpr auto CEC_2014_LOWER_BOUND = -100.0;
constexpr auto CEC_2014_UPPER_BOUND = 100.0;

class Cec2014ComplianceTest
    : public PerFuzzTestFixtureAdapter<CecTestFixture<cec_edition_t::cec2014, 10, 30, 50, 100>> {
public:
    void Cec2014D10ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2014ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2014D30ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2014ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2014D50ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2014ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2014D100ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2014ImplsAreEquivImpl(input, problem_num);
    }

private:
    void Cec2014ImplsAreEquivImpl(std::vector<double> input, int problem_num) {
        const auto oracle_output = calculate_oracle_output(oracle::cec2014::cec14_test_func, input, problem_num);

        const auto cecxx_output = cec_evaluator(problem_num, cecxx::mdspan{input.data(), input.size(), 1});
        EXPECT_NEAR(oracle_output, cecxx_output[0], MAX_ABS_ERROR);
    }
};

FUZZ_TEST_F(Cec2014ComplianceTest, Cec2014D10ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2014_LOWER_BOUND, CEC_2014_UPPER_BOUND)).WithSize(10),
                 InCecProblemRange(cec_edition_t::cec2014));

FUZZ_TEST_F(Cec2014ComplianceTest, Cec2014D30ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2014_LOWER_BOUND, CEC_2014_UPPER_BOUND)).WithSize(30),
                 InCecProblemRange(cec_edition_t::cec2014));

FUZZ_TEST_F(Cec2014ComplianceTest, Cec2014D50ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2014_LOWER_BOUND, CEC_2014_UPPER_BOUND)).WithSize(50),
                 InCecProblemRange(cec_edition_t::cec2014));

FUZZ_TEST_F(Cec2014ComplianceTest, Cec2014D100ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2014_LOWER_BOUND, CEC_2014_UPPER_BOUND)).WithSize(100),
                 InCecProblemRange(cec_edition_t::cec2014));
