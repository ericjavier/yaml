#ifndef SUB_SEQS_HPP_INCLUDED
#define SUB_SEQS_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/non_empty_seqs.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

//! Waiting for function composition
template<typename S>
using sub_seqs_tmpl = cons::ret<empty_seq, non_empty_seqs::ret<S>>;

END_DETAIL_NSP

using sub_seqs = make_curried_t<DETAIL_NSP_REF sub_seqs_tmpl>;

END_YAML_NSP

#endif SUB_SEQS_HPP_INCLUDED