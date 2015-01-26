#ifndef REPEAT_HPP_INCLUDED
#define REPEAT_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename T> struct repeat_tmpl {
  using type = seq<T, repeat_tmpl<T>>;
};

END_DETAIL_NSP

using repeat = curried_func_t<DETAIL_NSP_REF repeat_tmpl>;

END_YAML_NSP

#endif REPEAT_HPP_INCLUDED