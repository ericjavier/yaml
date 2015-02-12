#ifndef TAKE_HPP_INCLUDED
#define TAKE_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename N, typename S> class take_tmpl {

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
    using type = empty_seq;
  };

  template<std::size_t V, typename H, typename R>
  struct impl<std::integral_constant<std::size_t, V>, seq<H, R>> {
    using type = seq<H,
      impl<std::integral_constant<std::size_t, V - 1>, force_t<R>>>;
  };

public:

  using type = typename impl<force_t<N>, force_t<S>>::type;

};


END_DETAIL_NSP

using take = make_curried_t<DETAIL_NSP_REF take_tmpl>;

END_YAML_NSP

#endif TAKE_HPP_INCLUDED