#ifndef SPLIT_HPP_INCLUDED
#define SPLIT_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/take.hpp>
#include <yaml/sequence/drop.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename N, typename S> struct split_tmpl { 
  using type = pair<take::ret<N, S>, drop::ret<N, S>>;
};

END_DETAIL_NSP

/// \brief Gets a pair where the first item is a sufix and the second
///        the prefix of a given sequence.
using split = make_curried_t<DETAIL_NSP_REF split_tmpl>;

END_YAML_NSP

#endif SPLIT_HPP_INCLUDED