#ifndef SCAN_RIGHT_1_HPP_INCLUDED
#define SCAN_RIGHT_1_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/is_empty.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename S> class scan_right_1_tmpl {

  template<typename> struct impl;

  template<typename H, typename R> struct impl<seq<H, R>> {

    template<typename S, typename T> struct helper;

    template<typename H, typename R> struct helper<seq<H, R>, std::true_type> {
      using head = H;
      using type = seq<H, R>;
    };

    template<typename H, typename R> struct helper<seq<H, R>, std::false_type> {
      using temp = impl<force_t<R>>;
      using head = apply<F, H, typename temp::head>;
      using type = seq<head, temp>;
    };

    using is_last = typename apply<is_empty, R>::type;
    using temp = helper<seq<H, R>, is_last>;
    using head = typename temp::head;
    using type = typename temp::type;
  };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief A variant of 'scan_right' that has no starting value argument.
using scan_right_1 = curried_func_t<DETAIL_NSP_REF scan_right_1_tmpl>;

END_YAML_NSP

#endif SCAN_RIGHT_1_HPP_INCLUDED