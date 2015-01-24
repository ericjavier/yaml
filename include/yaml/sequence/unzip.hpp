#ifndef UNZIP_HPP_INCLUDED
#define UNZIP_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/fold_right.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S> class unzip_tmpl {

  template<typename P1, typename P2> struct red {
  
    template<typename, typename> struct impl;
  
    template<typename H1, typename H2, typename R1, typename R2>
    struct impl<pair_t<H1, H2>, pair_t<R1, R2>> { 
      using type = pair_t<seq<H1, R1>, seq<H2, R2>>;
    };

    using type = typename impl<force_t<P1>, force_t<P2>>::type;

  };

  using reductor = curried_func_t<red>;

public:

  using type = typename apply<fold_right, reductor,
    pair_t<empty_seq, empty_seq>, force_t<S>>::type;

};

END_DETAIL_NSP

using unzip = curried_func_t<DETAIL_NSP_REF unzip_tmpl>;

END_YAML_NSP

#endif UNZIP_HPP_INCLUDED