#pragma once

#include <concepts>

namespace cecxx::benchmark {
template <class T>
concept numeric = std::integral<T> or std::floating_point<T>;

template <class T>
concept problem_context = requires(T ctx) {
    T::shift;
    T::rotate;
    T::shuffle;
};
} // namespace cecxx::benchmark
