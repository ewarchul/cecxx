#pragma once

#include <cecxx/benchmark/types.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

struct dummy_optimizer {
  std::string name_{};
  dummy_optimizer(std::string name) : name_{name} {}

  auto name() const -> std::string { return name_; }

  auto operator()(auto&& evaluation_function, const std::vector<double>& input) const
      -> cecxx::benchmark::optimizer_output {
    // mock optimization process
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return {.best_values = std::vector{1.0, 5.0, 6.0}};
  }
};
