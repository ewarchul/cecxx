#pragma once

#include "oracle/cec2017.h"

auto calculate_oracle_output(std::vector<double>& input, const int problem_num) -> double {
  auto output = std::array<double, 1>{};
  cec17_test_func(input.data(), output.data(), input.size(), 1, problem_num);
  return output[0];
}
