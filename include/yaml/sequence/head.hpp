#ifndef HEAD_HPP_INCLUDED
#define HEAD_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\detail\force.hpp>
#include <yaml\sequence\sequence_fwd.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S> class head_tmpl {

  template<typename> struct impl;

  template<typename H, typename R> struct impl<seq<H, R>> {
    using type = H;
  };

public:

  using type = typename impl<typename force<S>::type>::type;
};

END_DETAIL_NSP

using head = create_curried_func<DETAIL_NSP_REF head_tmpl>::type;

END_YAML_NSP

#endif HEAD_HPP_INCLUDED