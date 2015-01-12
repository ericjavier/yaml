#ifndef LAST_HPP_INCLUDED
#define LAST_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\sequence\sequence_def.hpp>
#include <yaml\sequence\is_empty.hpp>
#include <yaml\sequence\last.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S> class last_tmpl {

  template<typename> struct impl;

  template<typename H, typename R> struct impl<seq<H, R>> {

    template<typename S, typename L> struct helper;

    template<typename H, typename R> struct helper<seq<H, R>, std::false_type> {
      using type = typename impl<force_t<R>>::type;
    };

    template<typename H, typename R> struct helper<seq<H, R>, std::true_type> {
      using type = H;
    };

    using is_last = typename apply<is_empty, R>::type;
    using type = typename helper<seq<H, R>, is_last>::type;

  };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Extract the last element of a sequence, which must be finite
///        and non-empty. 
using last = curried_func_t<DETAIL_NSP_REF last_tmpl>;

END_YAML_NSP

#endif LAST_HPP_INCLUDED