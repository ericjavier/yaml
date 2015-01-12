#ifndef LENGTH_HPP_INCLUDED
#define LENGTH_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\sequence\sequence_def.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S> class length_tmpl {

  template<typename> struct impl;

  template<> struct impl<empty_seq>
    : public std::integral_constant<std::size_t, 0> { };
    
  template<typename H, typename R> struct impl<seq<H, R>>
    : public std::integral_constant<std::size_t, impl<force_t<R>>::value + 1> {
  };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

using length = curried_func_t<DETAIL_NSP_REF length_tmpl>;

END_YAML_NSP

#endif LENGTH_HPP_INCLUDED