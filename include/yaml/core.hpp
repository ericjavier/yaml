#ifndef CORE_HPP_INCLUDED
#define CORE_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/detail/have_type.hpp>
#include <yaml/detail/cond.hpp>
#include <yaml/detail/template_fitting.hpp>
#include <yaml/detail/placeholders.hpp>
#include <yaml/detail/force.hpp>
#include <yaml/detail/take_from_variadic.hpp>

#include <type_traits>
#include <cstddef>


BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

/// \brief Internal helper type used to pack a list of types.
template<typename...> struct ls;

/// \brief Creates the initial placeholders of a given template. Is used to 
///        initialize curried functions.
template<template<class...> class T> class initial_phs { 

  template<std::size_t S, typename... As> struct impl {

    using type = typename cond<
      fitting_t<T, As...>,
      ls<As...>,
      impl<(S + 1), As..., ph<S + 1>>>::type;
  };

public:

  using type = typename impl<0, ph<0>>::type;
};

/// \brief Used to represent the state of a curried function.
///        N:  is the number of arguments.
///        M:  is the number of placeholders
///        Ss: the arguments
template<std::size_t N, std::size_t M, typename... Ss>
struct currying_state;

/// \brief Used to represent the arguments passed to a curried function.
///        N:  is the number of arguments.
///        M:  is the number of placeholders
///        As: the arguments
/// \NOTE  'form' stands for formalized
template<std::size_t M, std::size_t K, typename... As> struct form_args;

/// \brief Converts a list of arguments to a formalized list of N arguments.
///        For example it introduce missing placeholders.
template<std::size_t N, typename... As> class formalize_args { 

  template<typename, typename...> struct impl;

  template<std::size_t M, std::size_t K, typename... U>
  struct impl<form_args<M, K, U...>> {
    using type = typename cond<
      std::integral_constant<bool, (sizeof...(U) == M)>,
      form_args<M, K, U...>,
      impl<form_args<M, K + 1, U..., ph<K>>>>::type;
  };

  template<
    std::size_t M, std::size_t K, std::size_t P, typename... U, typename... R>
  struct impl<form_args<M, K, U...>, ph<P>, R...> {
    using type = typename impl<form_args<M, K + 1, U..., ph<P>>, R...>::type;
  };

  template<
    std::size_t M, std::size_t K, typename... U, typename F, typename... R>
  struct impl<form_args<M, K, U...>, F, R...> {
    using type = typename impl<form_args<M, K, U..., F>, R...>::type;
  };

public:

  using type = typename impl<form_args<N, 0>, As...>::type;

};

/// \brief Transition function from a curried state to another.
template<typename S, typename A> class move_state;

template<
  std::size_t N, std::size_t M, std::size_t K, typename... Ss, typename... As>
class move_state<currying_state<N, M, Ss...>, form_args<M, K, As...>> {

  template<typename Ss, typename As, typename Rs> struct impl;

  template<typename... As, typename... Rs>
  struct impl<ls<>, ls<As...>, ls<Rs...>> {
    using type = currying_state<N, K, Rs...>;
  };

  template<typename S, typename... Ss, typename... As, typename... Rs>
  struct impl<ls<S, Ss...>, ls<As...>, ls<Rs...>> {
    using type = typename impl<ls<Ss...>, ls<As...>, ls<Rs..., S>>::type;
  };

  template<std::size_t P, typename... Ss, typename... As, typename... Rs>
  struct impl<ls<ph<P>, Ss...>, ls<As...>, ls<Rs...>> {
    using it = typename take_from_variadic<P, As...>::type;
    using type = typename impl<ls<Ss...>, ls<As...>, ls<Rs..., it>>::type;
  };

public:

  using type = typename impl<ls<Ss...>, ls<As...>, ls<>>::type;

};

/// \brief Creates the initial curried function state from a template.
template<template<class...> class F> class make_state {

  template<typename> struct helper;

  template<typename... As> struct helper<ls<As...>> {
    const static std::size_t size = sizeof...(As);
    using type = currying_state<size, size, As...>;
  };

public:

  using type = typename helper<typename initial_phs<F>::type>::type;
};

/// \brief Type that encodes the currying.
template<template <class...> class F, typename S> class curried_t {

  template<typename> struct helper;

  template<std::size_t N, std::size_t K, typename... Rs>
  struct helper<currying_state<N, K, Rs...>> {
    using type = curried_t<F, currying_state<N, K, Rs...>>;
  };

  template<std::size_t N, typename... Rs>
  struct helper<currying_state<N, 0, Rs...>> {
    using type = typename F<Rs...>::type;
  };

  template<typename> struct impl;

  template<std::size_t N, std::size_t M, typename... Ss>
  struct impl<currying_state<N, M, Ss...>> {

    using current_state = currying_state<N, M, Ss...>;

    template<typename... As> using ret = typename helper<
      typename move_state<current_state, 
      typename formalize_args<M, As...>::type>::type>::type;
  };

public:
  
  template<typename... As> using ret = typename impl<S>::template ret<As...>;

};

template<template <class...> class F>
using make_curried_t = curried_t<F, typename make_state<F>::type>;

/// \brief flip F takes its (first) two arguments in the reverse order of F.
template<typename F> struct flip_tmpl { 
  using type = typename F::template ret<_1, _0>;
};

template<typename T> struct id_tmpl {
  using type = T;
};

template<typename A, typename...> struct constant_tmpl {
  using type = A;
};

template<typename L, typename R> struct is_same_tmpl {
  using type = std::integral_constant<bool, std::is_same<force_t<L>, force_t<R>>::value>;
};

END_DETAIL_NSP

using DETAIL_NSP_REF make_curried_t;
using DETAIL_NSP_REF force_t;

/// \brief A function to test if two types represent the same.
using is_same = make_curried_t<DETAIL_NSP_REF is_same_tmpl>;

/// \brief A pair of types.
template<typename T1, typename T2> struct pair { 
  using first_type = T1;
  using second_type = T2;
  using type = pair<T1, T2>;
};

/// \brief Creates a pair from two types.
using make_pair = make_curried_t<pair>;

/// \brief flip F takes its (first) two arguments in the reverse order of F.
using flip = make_curried_t<DETAIL_NSP_REF flip_tmpl>;

/// \brief Identity function.
using id = make_curried_t<DETAIL_NSP_REF id_tmpl>;

/// \brief Constant function.
using constant = make_curried_t<DETAIL_NSP_REF constant_tmpl>;

/// \brief Type used to codify the absent of a viable result.
struct nothing { };

END_YAML_NSP

#endif CORE_HPP_INCLUDED