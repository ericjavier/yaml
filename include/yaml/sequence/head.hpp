#ifndef HEAD_HPP_INCLUDED
#define HEAD_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S> class head_tmpl {

  template<typename> struct impl;

  template<typename H, typename R> struct impl<seq<H, R>> {
    using type = H;
  };

public:

  using type = typename impl<force_t<S>>::type;
};

END_DETAIL_NSP

///\brief Extract the first element of a sequence, which must be non-empty. 
using head = make_curried_t<DETAIL_NSP_REF head_tmpl>;

END_YAML_NSP

#endif HEAD_HPP_INCLUDED