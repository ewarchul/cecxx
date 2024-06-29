#pragma once

#include <cstdio>
#include <filesystem>
#include <vector>

#include "cecxx/benchmark/concepts.hpp"
#include "cecxx/benchmark/detail/types.hpp"
#include "util.hpp"

namespace cecxx::benchmark::detail {

struct FILE_deleter_t {
  auto operator()(std::FILE *ptr) { std::fclose(ptr); }
};

struct table_size_t {
  usize size{};
  i64 scaler{};
  bool scaler_applied{false};
};

auto ROT_TABLE_FILENAME(const std::filesystem::path &datadir, const usize dim,
                        const usize fn) -> std::string;
auto SHUFFLE_TABLE_FILENAME(const std::filesystem::path &datadir,
                            const usize dim, const usize fn) -> std::string;
auto SHIFT_TABLE_FILENAME(const std::filesystem::path &datadir, const usize,
                          const usize fn) -> std::string;

auto ROT_TABLE_SIZE(const usize dim, const usize fn) -> table_size_t;
auto SHIFT_TABLE_SIZE(const usize dim, const usize fn) -> table_size_t;
auto SHUFFLE_TABLE_SIZE(const usize dim, const usize fn) -> table_size_t;

template <table_type_t Table, typename... Args>
constexpr auto get_table_name(const std::filesystem::path &datapath,
                              Args... args) {
  switch (Table) {
  case table_type_t::rotate:
    return ROT_TABLE_FILENAME(datapath, args...);
  case table_type_t::shuffle:
    return SHUFFLE_TABLE_FILENAME(datapath, args...);
  case table_type_t::shift:
    return SHIFT_TABLE_FILENAME(datapath, args...);
  }

  throw std::runtime_error("Unknown table type.");
}

template <table_type_t Table, typename ValueType>
constexpr auto get_table_size(const usize dim, const usize fn) {
  switch (Table) {
  case table_type_t::rotate:
    return ROT_TABLE_SIZE(dim, fn);
  case table_type_t::shift:
    return SHIFT_TABLE_SIZE(dim, fn);
  case table_type_t::shuffle:
    return SHUFFLE_TABLE_SIZE(dim, fn);
  }

  throw std::runtime_error("Unknown table type.");
}

template <table_type_t Table, numeric T>
auto scan_table(auto *fs, const usize dim, const usize fn) -> std::vector<T> {
  const auto sz_info = get_table_size<Table, T>(dim, fn);
  auto table = std::vector<T>(sz_info.size);

  const auto scan_scaled_shift_table = [&]() {
    for (auto i = 0u; i < sz_info.scaler - 1; ++i) {
      for (auto j = 0u; j < dim; ++j) {
        if (std::fscanf(fs, number_formatter<T>().data(),
                        &table[i * dim + j]) == -1) {
          throw std::runtime_error{"Failed to parse table data from file."};
        }
      }
      std::fscanf(fs, "%*[^\n]%*c");
    }
  };

  if (Table == table_type_t::shift and sz_info.scaler_applied) {
    scan_scaled_shift_table();
    return table;
  }

  for (auto i = 0u; i < sz_info.size; ++i) {
    if (std::fscanf(fs, number_formatter<T>().data(), &table[i]) == -1) {
      throw std::runtime_error{"Failed to parse table data from file."};
    }
  }
  return table;
}

template <table_type_t Table, numeric T>
auto load_table_data(const std::filesystem::path &datapath, const usize dim,
                     const usize fn) {
  const auto filename = get_table_name<Table>(datapath, dim, fn);
  auto fs_ptr = std::unique_ptr<std::FILE, FILE_deleter_t>{
      std::fopen(filename.data(), "r")};
  if (not fs_ptr) {
    throw std::runtime_error{"Failed to open [" + filename + "]."};
  }

  return scan_table<Table, T>(fs_ptr.get(), dim, fn);
}

} // namespace cecxx::benchmark::detail
