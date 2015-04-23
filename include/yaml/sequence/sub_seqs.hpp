#ifndef SUB_SEQS_HPP_INCLUDED
#define SUB_SEQS_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/non_empty_seqs.hpp>

BEGIN_YAML_NSP

using sub_seqs = compose::ret<cons::ret<empty_seq>, non_empty_seqs>;

END_YAML_NSP

#endif SUB_SEQS_HPP_INCLUDED