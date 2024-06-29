#pragma once

#include <ranges>

namespace cecxx::benchmark {
template <class T>
concept numeric = std::integral<T> or std::floating_point<T>;

// this shall be replaced with mdspan from c++23
template <class R, class T>
concept matrix = std::convertible_to<
    std::ranges::range_reference_t<std::ranges::range_reference_t<R>>, T>;
} // namespace cecxx::benchmark
