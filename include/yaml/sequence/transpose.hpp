#ifndef TRANSPOSE_HPP_INCLUDED
#define TRANSPOSE_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/map.hpp>
#include <yaml/sequence/head.hpp>
#include <yaml/sequence/tail.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S> class transpose_tmpl {
  
  template<typename> struct impl;

  template<> struct impl<empty_seq> {
    using type = empty_seq;
  };

  template<typename H, typename R> struct impl<seq<H, R>> {
    
    template<typename H, typename R> struct helper {
      using seq_type = seq<H, R>;
      using heads = map::ret<head, seq_type>; 
      using tails = map::ret<tail, seq_type>; 
      using type = seq<heads, impl<tails>>;
    };

    template<typename R> struct helper<empty_seq, R> {
      using type = typename impl<force_t<R>>::type;
    };

    using type = typename helper<force_t<H>, force_t<R>>::type;

  };
  
public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

/// brief Transposes the rows and columns of its argument.
using transpose = make_curried_t<DETAIL_NSP_REF transpose_tmpl>;

END_YAML_NSP

#endif TRANSPOSE_HPP_INCLUDED 