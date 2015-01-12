#ifndef FILTER_HPP_INCLUDED
#define FILTER_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\sequence\sequence_def.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename S> class filter_tmpl {

  template<typename> struct impl;

  template<> struct impl<empty_seq> {
    using type = empty_seq;
  };

  template<typename H, typename R> struct impl<seq<H, R>> {

    template<typename, typename> struct helper;

    template<typename H, typename R> struct helper<seq<H, R>, std::false_type> {
      using type = typename impl<force_t<R>>::type;
    };

    template<typename H, typename R> struct helper<seq<H, R>, std::true_type> {
      using type = seq<H, impl<force_t<R>>>;
    };

    using pred_result = typename apply<F, H>::type;
    using type = typename helper<seq<H, R>, pred_result>::type;
    
  };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Applied to a predicate and a sequence, returns the sequence of
///        those elements that satisfy the predicate.
using filter = curried_func_t<DETAIL_NSP_REF filter_tmpl>;

END_YAML_NSP

#endif FILTER_HPP_INCLUDED