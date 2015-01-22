#ifndef ZIP_WITH_HPP_INCLUDED
#define ZIP_WITH_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename S0, typename S1> class zip_with_tmpl {

  template<typename, typename> struct impl;

  template<> struct impl<empty_seq, empty_seq> {
    using type = empty_seq;
  };

  template<typename S0> struct impl<S0, empty_seq> {
    using type = empty_seq;
  };

  template<typename S1> struct impl<empty_seq, S1> {
    using type = empty_seq;
  };

  template<typename H0, typename R0, typename H1, typename R1>
  struct impl<seq<H0, R0>, seq<H1, R1>> {
    using type = seq<typename apply<F, H0, H1>::type,
      impl<force_t<R0>, force_t<R1>>>;
  };

public:

  using type = typename impl<force_t<S0>, force_t<S1>>::type;

};

END_DETAIL_NSP

using zip_with = curried_func_t<DETAIL_NSP_REF zip_with_tmpl>;

END_YAML_NSP

#endif ZIP_WITH_HPP_INCLUDED