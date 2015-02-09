#ifndef INTERSPERSE_HPP_INCLUDED
#define INTERSPERSE_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename X, typename S> class intersperse_tmpl {

  template<typename> struct prepend_to_all;

  template<> struct prepend_to_all<empty_seq> {
    using type = empty_seq;
  };

  template<typename H, typename R> struct prepend_to_all<seq<H, R>> {
    using type = seq<X, seq<H, prepend_to_all<force_t<R>>>>;
  };

  template<typename> struct impl;

  template<> struct impl<empty_seq> {
    using type = empty_seq;
  };

  template<typename H, typename R> struct impl<seq<H, R>> {
    using type = seq<H, prepend_to_all<force_t<R>>>;
  };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Takes an element and a list and `intersperses' that element 
///        between the elements of the list.
using intersperse = curried_func_t<DETAIL_NSP_REF intersperse_tmpl>;

END_YAML_NSP

#endif INTERSPERSE_HPP_INCLUDED