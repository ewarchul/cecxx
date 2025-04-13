#pragma once

#include <cecxx/benchmark/types.hpp>
#include <set>
#include <unordered_map>

namespace cecxx::benchmark::cec_2013 {
const auto OFFSETS = std::unordered_map<problem_number_t, double>{
    {1, 1400.0}, {2, 1300.0}, {3, 1200.0},  {4, 1100.0},  {5, 1000.0},  {6, 900.0},   {7, 800.0},
    {8, 700.0},  {9, 600.0},  {10, 500.0},  {11, 400.0},  {12, 300.0},  {13, 200.0},  {14, 100.0},
    {15, 100.0}, {16, 200.0}, {17, 300.0},  {18, 400.0},  {19, 500.0},  {20, 600.0},  {21, 700.0},
    {22, 800.0}, {23, 900.0}, {24, 1000.0}, {25, 1100.0}, {26, 1200.0}, {27, 1300.0}, {28, 1400.0}};

const auto VALID_DIMENSIONS = std::set<dimension_t>{2, 5, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

} // namespace cecxx::benchmark::cec_2013
