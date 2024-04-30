#pragma once

#include <type_traits>
#include <vector>

namespace cecxx::benchmark::detail {

template <typename Enum> constexpr auto to_underlying(Enum e) noexcept -> std::underlying_type_t<Enum> {
  return static_cast<std::underlying_type_t<Enum>>(e);
}

using fn_num = int;
template <typename T> using table_data = std::vector<T>;

enum class table_type_t { rotate, shift, shuffle };

enum class do_affine_trans : bool { yes = true, no = false };

struct affine_mask_t {
  do_affine_trans rot{};
  do_affine_trans shift{};
  do_affine_trans shuffle{};
  double rate{1.0};
};

}  // namespace cecxx::benchmark::detail
