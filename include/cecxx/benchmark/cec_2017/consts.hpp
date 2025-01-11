#pragma once

#include "cecxx/benchmark/types.hpp"
#include <set>
#include <unordered_map>

namespace cecxx::benchmark::cec_2017 {
const auto OFFSETS = std::unordered_map<problem_number_t, double>{
    {1, 100.0},   {2, 200.0},   {3, 300.0},   {4, 400.0},   {5, 500.0},   {6, 600.0},   {7, 700.0},   {8, 800.0},
    {9, 900.0},   {10, 1000.0}, {11, 1100.0}, {12, 1200.0}, {13, 1300.0}, {14, 1400.0}, {15, 1500.0}, {16, 1600.0},
    {17, 1700.0}, {18, 1800.0}, {19, 1900.0}, {20, 2000.0}, {21, 2100.0}, {22, 2200.0}, {23, 2300.0}, {24, 2400.0},
    {25, 2500.0}, {26, 2600.0}, {27, 2700.0}, {28, 2800.0}, {29, 2900.0}, {30, 3000.0},
};

const auto VALID_DIMENSIONS = std::set<dimension_t>{10, 30, 50, 100};

} // namespace cecxx::benchmark::cec_2017
