#pragma once

#include <cstdio>
#include <filesystem>
#include <utility>
#include <vector>

#include <cecxx/benchmark/concepts.hpp>
#include <cecxx/benchmark/types.hpp>

namespace cecxx::benchmark::detail {

template <typename T>
constexpr auto number_formatter() -> std::string_view {
    if (std::same_as<T, double>) {
        return "%lf";
    } else if (std::same_as<T, unsigned int>) {
        return "%d";
    }

    std::unreachable();
}

struct FILE_deleter_t {
    auto operator()(std::FILE *ptr) {
        std::fclose(ptr);
    }
};

struct table_size_t {
    std::size_t size{};
    std::size_t scaler{};
    bool scaler_applied{false};
};

auto ROT_TABLE_FILENAME(const cec_edition_t edition, const std::filesystem::path &datadir, const dimension_t dim,
                        const problem_number_t fn) -> std::string;
auto SHUFFLE_TABLE_FILENAME(const cec_edition_t edition, const std::filesystem::path &datadir, const dimension_t dim,
                            const problem_number_t fn) -> std::string;
auto SHIFT_TABLE_FILENAME(const cec_edition_t edition, const std::filesystem::path &datadir, const dimension_t,
                          const problem_number_t fn) -> std::string;

auto ROT_TABLE_SIZE(const cec_edition_t edition, const dimension_t dim, const problem_number_t fn) -> table_size_t;
auto SHIFT_TABLE_SIZE(const cec_edition_t edition, const dimension_t dim, const problem_number_t fn) -> table_size_t;
auto SHUFFLE_TABLE_SIZE(const cec_edition_t edition, const dimension_t dim, const problem_number_t fn) -> table_size_t;

template <table_type_t Table, typename... Args>
constexpr auto get_table_name(const cec_edition_t edition, const std::filesystem::path &datapath, Args... args) {
    switch (Table) {
        case table_type_t::rotate:
            return ROT_TABLE_FILENAME(edition, datapath, args...);
        case table_type_t::shuffle:
            return SHUFFLE_TABLE_FILENAME(edition, datapath, args...);
        case table_type_t::shift:
            return SHIFT_TABLE_FILENAME(edition, datapath, args...);
    }

    std::unreachable();
}

template <table_type_t Table, typename ValueType>
constexpr auto get_table_size(const cec_edition_t edition, const dimension_t dim, const problem_number_t fn) {
    switch (Table) {
        case table_type_t::rotate:
            return ROT_TABLE_SIZE(edition, dim, fn);
        case table_type_t::shift:
            return SHIFT_TABLE_SIZE(edition, dim, fn);
        case table_type_t::shuffle:
            return SHUFFLE_TABLE_SIZE(edition, dim, fn);
    }
    std::unreachable();
}

template <table_type_t Table, numeric T>
auto scan_table(const cec_edition_t edition, auto *fs, const dimension_t dim, const problem_number_t fn)
    -> std::vector<T> {
    const auto sz_info = get_table_size<Table, T>(edition, dim, fn);
    auto table = std::vector<T>(sz_info.size);

    const auto scan_scaled_shift_table = [&]() {
        for (auto i = 0uz; i < sz_info.scaler - 1; ++i) {
            for (auto j = 0u; j < dim; ++j) {
                if (std::fscanf(fs, number_formatter<T>().data(), &table[i * dim + j]) == -1) {
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
auto load_table_data(const cec_edition_t edition, const std::filesystem::path &datapath, const dimension_t dim,
                     const problem_number_t fn) {
    if (Table == table_type_t::shuffle and edition == cec_edition_t::cec2013) {
        return table_data<T>{};
    }
    const auto filename = get_table_name<Table>(edition, datapath, dim, fn);
    auto fs_ptr = std::unique_ptr<std::FILE, FILE_deleter_t>{std::fopen(filename.data(), "r")};
    if (not fs_ptr) {
        throw std::runtime_error{"Failed to open [" + filename + "]."};
    }

    return scan_table<Table, T>(edition, fs_ptr.get(), dim, fn);
}

} // namespace cecxx::benchmark::detail
