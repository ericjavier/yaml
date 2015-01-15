#ifndef DROP_HPP_INCLUDED
#define DROP_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename N, typename S> struct drop_tmpl {

  template<typename, typename> struct impl;

  template<> struct impl<std::integral_constant<std::size_t, 0>, empty_seq> {
    using type = empty_seq;
  };

  template<std::size_t V>
  struct impl<std::integral_constant<std::size_t, V>, empty_seq> {
    using type = empty_seq;
  };

  template<typename H, typename R>
  struct impl<std::integral_constant<std::size_t, 0>, seq<H, R>> {
    using type = seq<H, R>;
  };

  template<std::size_t V, typename H, typename R>
  struct impl<std::integral_constant<std::size_t, V>, seq<H, R>> {
    using type = typename impl<
      std::integral_constant<std::size_t, V - 1>, force_t<R>>::type;
  };

public:

  using type = typename impl<force_t<N>, force_t<S>>::type;

};

END_DETAIL_NSP

using drop = curried_func_t<DETAIL_NSP_REF drop_tmpl>;

END_YAML_NSP

#endif DROP_HPP_INCLUDED