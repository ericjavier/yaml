#ifndef DETAIL_TAKE_FROM_VARIADIC_HPP_INCLUDED
#define DETAIL_TAKE_FROM_VARIADIC_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/detail/cond.hpp>
#include <cstddef>
#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

/// \brief Helper function used to take an argument from a variadic set of them.
template<std::size_t, typename...> struct take_from_variadic;

template<std::size_t P, typename F, typename... R>
struct take_from_variadic<P, F, R...> {
  using type = typename cond<std::integral_constant<bool, (P == 0)>,
    F, take_from_variadic<(P - 1), R...>>::type;
};

END_DETAIL_NSP

END_YAML_NSP

#endif DETAIL_TAKE_FROM_VARIADIC_HPP_INCLUDED