#ifndef FIND_ALL_HPP_INCLUDED
#define FIND_ALL_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename S> class find_all_tmpl {

  template<typename> struct impl;

  template<> struct impl<empty_seq> {
    using type = empty_seq;
  };

  template<typename H, typename R> struct impl<seq<H, R>> {

    template<typename, typename> struct helper;

    template<typename H, typename R> struct helper<seq<H, R>, std::true_type> {
      using type = seq<H, impl<force_t<R>>>;
    };

    template<typename H, typename R> struct helper<seq<H, R>, std::false_type> {
      using type = typename impl<force_t<R>>::type;
    };

    using type = typename helper<seq<H, R>, typename F::template ret<H>>::type;

  };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

using find_all = make_curried_t<DETAIL_NSP_REF find_all_tmpl>;

END_YAML_NSP

#endif FIND_ALL_HPP_INCLUDED