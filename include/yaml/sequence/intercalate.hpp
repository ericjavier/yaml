#ifndef INTERCALATE_HPP_INCLUDED
#define INTERCALATE_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/concat.hpp>
#include <yaml/sequence/intersperse.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S, typename Ss> struct intercalate_tmpl {
  using type = concat::ret<intersperse::ret<S, Ss>>;
};

END_DETAIL_NSP

using intercalate = make_curried_t<DETAIL_NSP_REF intercalate_tmpl>;

// using intercalate = compose::ret<concat, intersperse>;

END_YAML_NSP

#endif INTERCALATE_HPP_INCLUDED