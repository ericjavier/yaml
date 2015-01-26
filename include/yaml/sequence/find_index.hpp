#ifndef FIND_INDEX_HPP_INCLUDED
#define FIND_INDEX_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename S> class find_index_tmpl {

  template<std::size_t, typename> struct impl;

  template<std::size_t I> struct impl<I, empty_seq> {
    using type = nothing;
  };

  template<std::size_t I, typename H, typename R> struct impl<I, seq<H, R>> {

    template<std::size_t, typename, typename> struct helper;

    template<std::size_t I, typename H, typename R>
    struct helper<I, seq<H, R>, std::true_type> {
      using type = std::integral_constant<std::size_t, I>;
    };

    template<std::size_t I, typename H, typename R>
    struct helper<I, seq<H, R>, std::false_type> {
      using type = typename impl<(I + 1), force_t<R>>::type;
    };

    using type = typename helper<I, seq<H, R>, apply_t<F, H>>::type;

  };

public:

  using type = typename impl<0, force_t<S>>::type;

};

END_DETAIL_NSP

using find_index = curried_func_t<DETAIL_NSP_REF find_index_tmpl>;

END_YAML_NSP

#endif FIND_INDEX_HPP_INCLUDED