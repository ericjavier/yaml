#ifndef FOLD_LEFT_HPP_INCLUDED
#define FOLD_LEFT_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename I, typename S> class fold_left_tmpl {

  template<typename I, typename S> struct impl;

  template<typename I> struct impl<I, empty_seq> {
    using type = I;
  };

  template<typename I, typename H, typename R> struct impl<I, seq<H, R>> {
    using type = typename impl<apply<F, I, H>, force_t<R>>::type;
  };

public:

  using type = typename impl<force_t<I>, force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Reduces the sequence using the binary function, from left to right.
using fold_left = curried_func_t<DETAIL_NSP_REF fold_left_tmpl>;

END_YAML_NSP

#endif FOLD_LEFT_HPP_INCLUDED