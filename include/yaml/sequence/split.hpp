#ifndef SPLIT_HPP_INCLUDED
#define SPLIT_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/take.hpp>
#include <yaml/sequence/drop.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename N, typename S> class split_tmpl { 

  using take_result = typename apply<take, N, S>::type;
  using drop_result = typename apply<drop, N, S>::type;

public:

  using type = pair<take_result, drop_result>;
};

END_DETAIL_NSP

/// \brief Gets a pair where the first item is a sufix and the second
///        the prefix of a given sequence.
using split = curried_func_t<DETAIL_NSP_REF split_tmpl>;

END_YAML_NSP

#endif SPLIT_HPP_INCLUDED