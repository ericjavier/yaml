#ifndef SCAN_RIGHT_HPP_INCLUDED
#define SCAN_RIGHT_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/head.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename I, typename S> class scan_right_tmpl {

  template<typename, typename> struct impl;

  template<typename I> struct impl<I, empty_seq> {
    using type = seq<I, empty_seq>;
    using head = I;
  };

  template<typename I, typename H, typename R> struct impl<I, seq<H, R>> {
    using temp = impl<I, force_t<R>>;
    using head = apply<F, H, typename temp::head>;
    using type = seq<head, temp>;
  };

public:

  using type = typename impl<force_t<I>, force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Similar to 'fold_right', but returns a sequence of successive reduced
///        values from the right.
using scan_right = curried_func_t<DETAIL_NSP_REF scan_right_tmpl>;

END_YAML_NSP

#endif SCAN_RIGHT_HPP_INCLUDED