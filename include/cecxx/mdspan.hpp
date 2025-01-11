#pragma once

#define MDSPAN_USE_PAREN_OPERATOR 1

#if defined(__GNUC__)

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wold-style-cast"

#endif

#include "cecxx/detail/mdspan/mdspan"

#if defined(__GNUC__)

#pragma GCC diagnostic pop

#endif

#undef MDSPAN_USE_PAREN_OPERATOR

namespace cecxx {

template <typename T, typename Extents, typename LayoutPolicy = std::experimental::layout_right,
          typename AccessorPolicy = std::experimental::default_accessor<T> >
using mdspan = std::experimental::mdspan<T, Extents, LayoutPolicy, AccessorPolicy>;

template <typename IndexType, std::size_t... Extents>
using extents = std::experimental::extents<IndexType, Extents...>;

template <typename IndexType, std::size_t Rank>
using dextents = std::experimental::dextents<IndexType, Rank>;

} // namespace cecxx
