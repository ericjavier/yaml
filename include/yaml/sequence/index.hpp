#ifndef INDEX_HPP_INCLUDED
#define INDEX_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename I, typename S> class index_tmpl {
  
  template<typename I, typename S> struct impl;
 
  template<typename H, typename R>
  struct impl<std::integral_constant<std::size_t, 0>, seq<H, R>> {
    using type = H;
  };
  
  template<std::size_t V, typename H, typename R>
  struct impl<std::integral_constant<std::size_t, V>, seq<H, R>> {
    using type = typename impl<std::integral_constant<std::size_t, V - 1>, 
      force_t<R>>::type;
  };
  
public:

  using type = typename impl<force_t<I>, force_t<S>>::type;
  
};

END_DETAIL_NSP

/// \brief Index a sequence, starting from 0.
using index = make_curried_t<DETAIL_NSP_REF index_tmpl>;

END_YAML_NSP

#endif INDEX_HPP_INCLUDED