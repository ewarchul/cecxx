#pragma once

template <class Oracle>
auto calculate_oracle_output(Oracle &&oracle, std::vector<double> &input, const int problem_num) -> double {
    auto output = std::array<double, 1>{};
    oracle(input.data(), output.data(), input.size(), 1, problem_num);
    return output[0];
}
