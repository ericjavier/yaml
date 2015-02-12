#ifndef TAIL_HPP_INCLUDED
#define TAIL_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S> class tail_tmpl {

  template<typename> struct impl;

  template<typename H, typename R> struct impl<seq<H, R>> {
    using type = R;
  };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Extract the elements after the head of a sequence, which must
///        be non-empty.
using tail = make_curried_t<DETAIL_NSP_REF tail_tmpl>;

END_YAML_NSP

#endif TAIL_HPP_INCLUDED