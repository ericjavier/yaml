#ifndef DETAIL_FORCE_HPP_INCLUDED
#define DETAIL_FORCE_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/detail/have_type.hpp>

#include <type_traits>

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

END_DETAIL_NSP

END_YAML_NSP

#endif DETAIL_FORCE_HPP_INCLUDED