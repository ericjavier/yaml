#ifndef SCAN_LEFT_HPP_INCLUDED
#define SCAN_LEFT_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename I, typename S> class scan_left_tmpl {

  template<typename, typename> struct impl;

  template<typename I> struct impl<I, empty_seq> {
    using type = seq<I, empty_seq>;
  };
    
  template<typename I, typename H, typename R> struct impl<I, seq<H, R>> {
    using type = seq<I, impl<typename apply<F, I, H>::type, force_t<R>>>;
  };

public:

  using type = typename impl<force_t<I>, force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Similar to 'fold_left', but returns a sequence of successive reduced
///        values from the left.
using scan_left = curried_func_t<DETAIL_NSP_REF scan_left_tmpl>;

END_YAML_NSP

#endif SCAN_LEFT_HPP_INCLUDED