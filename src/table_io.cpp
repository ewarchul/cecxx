#include "table_io.hpp"

#include <string>
#include <utility>

namespace cecxx::benchmark::detail {
using namespace std::string_literals;

namespace {

constexpr auto has_extended_size(const int fn) -> bool { return (fn - 1) >= 21; }
}  // namespace

auto ROT_TABLE_FILENAME(const std::filesystem::path& datadir, const int dim, const int fn) -> std::string {
  return datadir / ("M_"s + std::to_string(fn) + "_D"s + std::to_string(dim) + ".txt");
}

auto SHUFFLE_TABLE_FILENAME(const std::filesystem::path& datadir, const int dim, const int fn) -> std::string {
  return datadir / ("shuffle_data_"s + std::to_string(fn) + "_D"s + std::to_string(dim) + ".txt");
}

auto SHIFT_TABLE_FILENAME(const std::filesystem::path& datadir, const int, const int fn) -> std::string {
  return datadir / ("shift_data_"s + std::to_string(fn) + ".txt");
}

auto ROT_TABLE_SIZE(const int dim, const int fn) -> table_size_t {
  constexpr auto funcTreshold = 20;
  constexpr auto coeff = 10;
  if (fn - 1 < funcTreshold) {
    return {.size = dim * dim, .scaler = coeff, .scaler_applied = false};
  }
  return {.size = dim * dim * coeff, .scaler = coeff, .scaler_applied = true};
}

auto SHIFT_TABLE_SIZE(const int dim, const int fn) -> table_size_t {
  constexpr int funcTreshold = 20;
  constexpr int coeff = 10;
  if (fn - 1 < funcTreshold) {
    return {.size = dim, .scaler = coeff, .scaler_applied = false};
  }
  return {.size = dim * coeff, .scaler = coeff, .scaler_applied = true};
}

auto SHUFFLE_TABLE_SIZE(const int dim, const int fn) -> table_size_t {
  constexpr auto coeff = 10;
  if (not has_extended_size(fn)) {
    return {.size = dim, .scaler = coeff, .scaler_applied = false};
  }

  return {.size = dim * coeff, .scaler = coeff, .scaler_applied = true};
}

}  // namespace cecxx::benchmark::detail
