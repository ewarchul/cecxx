#pragma once

#include <string>
#include <thread>
#include <vector>

#include <cecxx/benchmark/types.hpp>

struct dummy_optimizer {
  std::string name_{};
  dummy_optimizer(std::string name) : name_{name} {}

  auto name() -> std::string { return name_; }

  auto operator()(auto &&, std::vector<double>)
      -> cecxx::benchmark::optimizer_output {
    // mock optimization process
    std::this_thread::sleep_for(std::chrono::seconds(3));
    return {.best_values = std::vector{1.0, 5.0, 6.0}, .function_eval_num = 50};
  }
};
