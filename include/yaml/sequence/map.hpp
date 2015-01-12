#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\sequence\sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename S> class map_tmpl {

  template<typename> struct impl;

  template<> struct impl<empty_seq> {
    using type = empty_seq;
  };

  template<typename H, typename R> struct impl<seq<H, R>> {
    using type = seq<typename apply<F, H>::type, impl<force_t<R>>>;
  };

public:

  using type = typename impl<force_t<S>>::type;
};

END_DETAIL_NSP

/// \brief Gets the sequence obtained by applying a function to each
///        element of another.
using map = curried_func_t<DETAIL_NSP_REF map_tmpl>;

END_YAML_NSP

#endif MAP_HPP_INCLUDED