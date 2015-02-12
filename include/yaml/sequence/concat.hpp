#ifndef CONCAT_HPP_INCLUDED
#define CONCAT_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/append.hpp>
#include <yaml/sequence/fold_right.hpp>

BEGIN_YAML_NSP

using concat = fold_right::ret<append, empty_seq>;

END_DETAIL_NSP

#endif CONCAT_HPP_INCLUDED