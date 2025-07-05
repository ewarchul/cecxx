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
#include "oracle/cec2013.h"

using namespace fuzztest;
using namespace cecxx::benchmark;

constexpr auto MAX_ABS_ERROR = 1e-7;

constexpr auto CEC_2013_LOWER_BOUND = -100.0;
constexpr auto CEC_2013_UPPER_BOUND = 100.0;

class Cec2013ComplianceTest
    : public PerFuzzTestFixtureAdapter<CecTestFixture<cec_edition_t::cec2013, 2, 10, 20, 30, 50, 60, 80, 90, 100>> {
public:
    void Cec2013D2ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2013ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2013D10ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2013ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2013D20ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2013ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2013D30ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2013ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2013D50ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2013ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2013D60ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2013ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2013D80ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2013ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2013D90ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2013ImplsAreEquivImpl(input, problem_num);
    }

    void Cec2013D100ImplsAreEquiv(std::vector<double> input, int problem_num) {
        Cec2013ImplsAreEquivImpl(input, problem_num);
    }

private:
    void Cec2013ImplsAreEquivImpl(std::vector<double> input, int problem_num) {
        const auto oracle_output = calculate_oracle_output(oracle::cec2013::cec13_test_func, input, problem_num);

        const auto cecxx_output = cec_evaluator(problem_num, cecxx::mdspan{input.data(), input.size(), 1});
        EXPECT_NEAR(oracle_output, cecxx_output[0], MAX_ABS_ERROR);
    }
};

FUZZ_TEST_F(Cec2013ComplianceTest, Cec2013D2ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2013_LOWER_BOUND, CEC_2013_UPPER_BOUND)).WithSize(2),
                 InCecProblemRange(cec_edition_t::cec2013));

FUZZ_TEST_F(Cec2013ComplianceTest, Cec2013D10ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2013_LOWER_BOUND, CEC_2013_UPPER_BOUND)).WithSize(10),
                 InCecProblemRange(cec_edition_t::cec2013));

FUZZ_TEST_F(Cec2013ComplianceTest, Cec2013D20ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2013_LOWER_BOUND, CEC_2013_UPPER_BOUND)).WithSize(20),
                 InCecProblemRange(cec_edition_t::cec2013));

FUZZ_TEST_F(Cec2013ComplianceTest, Cec2013D30ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2013_LOWER_BOUND, CEC_2013_UPPER_BOUND)).WithSize(30),
                 InCecProblemRange(cec_edition_t::cec2013));

FUZZ_TEST_F(Cec2013ComplianceTest, Cec2013D50ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2013_LOWER_BOUND, CEC_2013_UPPER_BOUND)).WithSize(50),
                 InCecProblemRange(cec_edition_t::cec2013));

FUZZ_TEST_F(Cec2013ComplianceTest, Cec2013D60ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2013_LOWER_BOUND, CEC_2013_UPPER_BOUND)).WithSize(60),
                 InCecProblemRange(cec_edition_t::cec2013));

FUZZ_TEST_F(Cec2013ComplianceTest, Cec2013D80ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2013_LOWER_BOUND, CEC_2013_UPPER_BOUND)).WithSize(80),
                 InCecProblemRange(cec_edition_t::cec2013));

FUZZ_TEST_F(Cec2013ComplianceTest, Cec2013D90ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2013_LOWER_BOUND, CEC_2013_UPPER_BOUND)).WithSize(90),
                 InCecProblemRange(cec_edition_t::cec2013));

FUZZ_TEST_F(Cec2013ComplianceTest, Cec2013D100ImplsAreEquiv)
    .WithDomains(PositiveVectorOf<double>(InRange(CEC_2013_LOWER_BOUND, CEC_2013_UPPER_BOUND)).WithSize(100),
                 InCecProblemRange(cec_edition_t::cec2013));
