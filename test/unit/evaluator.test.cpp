#include <cecxx/benchmark/evaluator.hpp>
#include <cecxx/benchmark/helpers.hpp>
#include <cecxx/benchmark/types.hpp>
#include <gtest/gtest.h>
#include <ranges>

using namespace cecxx::benchmark;
namespace rv = std::ranges::views;
namespace rn = std::ranges;

// workaround for passing NTTP parameters to gtest's typed test suite
template <cec_edition_t Edition>
struct enum_wrapper {
    static constexpr cec_edition_t value = Edition;
};

template <typename Edition>
class EvaluatorTest : public testing::Test {
protected:
    EvaluatorTest() : eval_{Edition::value, valid_dimensions_, DATA_STORAGE_PATH} {}
    std::vector<std::size_t> valid_dimensions_{valid_dimensions(Edition::value)};
    int total_problem_num{cecxx::benchmark::total_problem_num(Edition::value)};
    evaluator eval_;
};

using TestedCecEditions = testing::Types<enum_wrapper<cec_edition_t::cec2017>>;

TYPED_TEST_SUITE(EvaluatorTest, TestedCecEditions);

TYPED_TEST(EvaluatorTest, EvaluatorShallEvaluateEachDProblemForGivenVector) {
    constexpr auto ncol = 1;
    const auto problem_grid
        = rv::cartesian_product(this->valid_dimensions_, rv::iota(1, total_problem_num(cec_edition_t::cec2017)));
    for (auto &&[dimension, problem_num] : problem_grid) {
        const auto given_input = rv::repeat(10.0) | rv::take(dimension * ncol) | rn::to<std::vector<double>>();
        EXPECT_NO_THROW(this->eval_(problem_num, cecxx::mdspan{given_input.data(), dimension, ncol}));
    }
}

TYPED_TEST(EvaluatorTest, EvaluatorShallEvaluateEachDProblemForGivenMatrix) {
    constexpr auto ncol = 20;
    const auto problem_grid
        = rv::cartesian_product(this->valid_dimensions_, rv::iota(1, total_problem_num(cec_edition_t::cec2017)));
    for (auto &&[dimension, problem_num] : problem_grid) {
        const auto given_input = rv::repeat(10.0) | rv::take(dimension * ncol) | rn::to<std::vector<double>>();
        EXPECT_NO_THROW(this->eval_(problem_num, cecxx::mdspan{given_input.data(), dimension, ncol}));
    }
}

TYPED_TEST(EvaluatorTest, EvaluatorShallThrowForInvalidDimension) {
    constexpr auto ncol = 1;
    constexpr auto invalid_dimensions = std::array{2, 33, 42, 101};
    const auto problem_grid
        = rv::cartesian_product(invalid_dimensions, rv::iota(1, total_problem_num(cec_edition_t::cec2017)));
    for (auto &&[dimension, problem_num] : problem_grid) {
        const auto given_input = rv::repeat(10.0) | rv::take(dimension * ncol) | rn::to<std::vector<double>>();
        EXPECT_THROW(this->eval_(problem_num, cecxx::mdspan{given_input.data(), given_input.size(), ncol}),
                     std::exception);
    }
}

TYPED_TEST(EvaluatorTest, EvaluatorShallThrowForInvalidProblemNumber) {
    constexpr auto ncol = 1;
    constexpr auto invalid_problems = std::array{32, 33, 42, 95};
    const auto problem_grid = rv::cartesian_product(this->valid_dimensions_, invalid_problems);
    for (auto &&[dimension, problem_num] : problem_grid) {
        const auto given_input = rv::repeat(10.0) | rv::take(dimension * ncol) | rn::to<std::vector<double>>();
        EXPECT_THROW(this->eval_(problem_num, cecxx::mdspan{given_input.data(), given_input.size(), ncol}),
                     std::exception);
    }
}

TYPED_TEST(EvaluatorTest, EvaluatorShallSupportExtractingProblems) {
    constexpr auto ncol = 20;
    const auto problem_grid
        = rv::cartesian_product(this->valid_dimensions_, rv::iota(1, total_problem_num(cec_edition_t::cec2017)));
    for (auto &&[dimension, problem_num] : problem_grid) {
        const auto given_input = rv::repeat(10.0) | rv::take(dimension * ncol) | rn::to<std::vector<double>>();
        auto extracted_problem = this->eval_.extract_problem(problem_num, dimension);
        EXPECT_NO_THROW(extracted_problem(cecxx::mdspan{given_input.data(), dimension, ncol}));
    }
}
