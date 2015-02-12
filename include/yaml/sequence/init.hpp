#ifndef INIT_HPP_INCLUDED
#define INIT_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/is_empty.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S> class init_tmpl {

  template<typename> struct impl;

  template<typename H, typename R> struct impl<seq<H, R>> {

    template<typename S, typename L> struct helper;

    template<typename H, typename R> struct helper<seq<H, R>, std::false_type> { 
      using type = seq<H, impl<force_t<R>>>;
    };
    
    template<typename H, typename R> struct helper<seq<H, R>, std::true_type> {
      using type = empty_seq; // to forget current
    };

    using is_last = is_empty::ret<R>;
    using type = typename helper<seq<H, R>, is_last>::type;

  };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Return all the elements of a sequence except the last one. 
///        The sequence must be non-empty.
using init = make_curried_t<DETAIL_NSP_REF init_tmpl>;

END_YAML_NSP

#endif INIT_HPP_INCLUDED