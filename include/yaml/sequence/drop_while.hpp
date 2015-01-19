#ifndef DROP_WHILE_HPP_INCLUDED
#define DROP_WHILE_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename P, typename S> class drop_while_tmpl {

  template<typename> struct impl;

  template<> struct impl<empty_seq> {
    using type = empty_seq;
  };

  template<typename H, typename R> struct impl<seq<H, R>> {

    template<typename, typename> struct helper;

    template<typename H, typename R> struct helper<seq<H, R>, std::true_type> {
      using type = typename impl<force_t<R>>::type;
    };

    template<typename H, typename R> struct helper<seq<H, R>, std::false_type> {
      using type = seq<H, R>;
    };

    using pred_result = typename apply<P, H>::type;
    using type = typename helper<seq<H, R>, pred_result>::type;

  };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

using drop_while = curried_func_t<DETAIL_NSP_REF drop_while_tmpl>;

END_YAML_NSP

#endif DROP_WHILE_HPP_INCLUDED