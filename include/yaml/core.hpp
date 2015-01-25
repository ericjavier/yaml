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

template<typename...> struct ls;

/// \brief Creates the initial placeholders of a given template. Is used to 
///        initialize curried functions.
template<template<class...> class T> class initial_placeholders { 

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
struct curried_func_state;

/// \brief Used to represent the arguments passed to a curried function.
///        N:  is the number of arguments.
///        M:  is the number of placeholders
///        As: the arguments
/// \NOTE  'form' stands for formalized
template<std::size_t M, std::size_t K, typename... As> struct form_args;

/// \brief To codify a curried function: T is the template, and S the state.
template<template<class...> class T, typename S> struct curried_func;

/// \brief Creates a curried function from a template.
template<template<class...> class T> class create_curried_func {

  template<typename> struct helper;

  template<typename... As> struct helper<ls<As...>> {
    const static std::size_t size = sizeof...(As);
    using state_t = curried_func_state<size, size, As...>;
    using type = curried_func<T, state_t>;
  };

public:

  using type = typename helper<typename initial_placeholders<T>::type>::type;
};

template<template<class...> class T>
using curried_func_t = typename create_curried_func<T>::type;

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
template<typename S, typename A> class next_state;

template<
  std::size_t N, std::size_t M, std::size_t K, typename... Ss, typename... As>
class next_state<curried_func_state<N, M, Ss...>, form_args<M, K, As...>> {

  template<typename Ss, typename As, typename Rs> struct impl;

  template<typename... As, typename... Rs>
  struct impl<ls<>, ls<As...>, ls<Rs...>> {
    using type = curried_func_state<N, K, Rs...>;
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

/// \brief Apply a set of arguments to a curried function.
template<typename F, typename... As> class apply { 

  template<typename, typename...> struct impl;

  template<
    template<class...> class T,
    std::size_t N,
    std::size_t M,
    typename... Ss,
    typename... Args>
  struct impl<curried_func<T, curried_func_state<N, M, Ss...>>, Args...> {

    using form_args = typename formalize_args<M, Args...>::type;
    using current_state = curried_func_state<N, M, Ss...>;
    using next_state = typename next_state<current_state, form_args>::type;

    template<typename> struct helper;

    template<std::size_t N, std::size_t K, typename... Rs>
    struct helper<curried_func_state<N, K, Rs...>> {
      using type = curried_func<T, curried_func_state<N, K, Rs...>>;
    };

    template<std::size_t N, typename... Rs>
    struct helper<curried_func_state<N, 0, Rs...>> {
      using type = typename T<Rs...>::type;
    };

    using type = typename helper<next_state>::type;

  };

public:

  using type = typename impl<F, As...>::type;
};

template<typename F, typename... As>
using apply_t = typename apply<F, As...>::type;

template<typename T1, typename T2> struct pair { 
  using first_type = T1;
  using second_type = T2;
  using type = pair<T1, T2>;
};

/// \brief Creates a pair from two types.
using make_pair = create_curried_func<pair>;

template<typename F> struct flip_tmpl { 
  using type = typename apply<F, _1, _0>::type;
};

/// \brief flip F takes its (first) two arguments in the reverse order of F.
using flip = curried_func_t<flip_tmpl>;

struct nothing { };

END_DETAIL_NSP

using DETAIL_NSP_REF curried_func_t;
using DETAIL_NSP_REF apply;
using DETAIL_NSP_REF apply_t;
using DETAIL_NSP_REF force_t;
using DETAIL_NSP_REF is_same;
using DETAIL_NSP_REF pair;
using DETAIL_NSP_REF make_pair;
using DETAIL_NSP_REF flip;
using DETAIL_NSP_REF nothing;

END_YAML_NSP

#endif CORE_HPP_INCLUDED