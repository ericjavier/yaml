#ifndef FOLD_RIGHT_HPP_INCLUDED
#define FOLD_RIGHT_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename I, typename S> class fold_right_tmpl {

  template<typename, typename> struct impl;

  template<typename I> struct impl<I, empty_seq> {
    using type = I;
  };

  template<typename I, typename H, typename R> struct impl<I, seq<H, R>> {
    using temp = typename impl<I, force_t<R>>::type;
    using type = typename F::template ret<H, temp>;
  };

public:

  using type = typename impl<force_t<I>, force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Reduces the sequence using the binary function, from right to left.
using fold_right = make_curried_t<DETAIL_NSP_REF fold_right_tmpl>;

END_YAML_NSP

#endif FOLD_RIGHT_HPP_INCLUDED