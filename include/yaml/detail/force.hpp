#ifndef DETAIL_FORCE_HPP_INCLUDED
#define DETAIL_FORCE_HPP_INCLUDED

#include <type_traits>

#include <yaml/config.hpp>
#include <yaml/detail/have_type.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

/// \brief Gets the value 'type' if T contains one, gets T otherwise.
template<typename T> class force {

  template<typename, typename> struct helper;

  template<typename U> struct helper<U, std::true_type> {
    using type = typename U::type;
  };

  template<typename U> struct helper<U, std::false_type> {
    using type = typename U;
  };

  using have_type = have_type_t<T>;

public:

  using type = typename helper<T, have_type>::type;
};

template<typename T> using force_t = typename force<T>::type;

template<typename L, typename R> struct is_same
  : std::integral_constant<bool, std::is_same<force_t<L>, force_t<R>>::value> {
};

END_DETAIL_NSP

END_YAML_NSP

#endif DETAIL_FORCE_HPP_INCLUDED