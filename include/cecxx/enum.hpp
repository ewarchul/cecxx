#pragma once

#include <type_traits>

namespace cecxx {
template <typename Enum>
constexpr auto to_underlying(Enum e) noexcept -> std::underlying_type_t<Enum> {
    return static_cast<std::underlying_type_t<Enum>>(e);
}

} // namespace cecxx
