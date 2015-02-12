#ifndef REVERSE_HPP_INCLUDED
#define REVERSE_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/fold_left.hpp>

BEGIN_YAML_NSP

/// \brief Returns the elements of a sequence in reverse order.
///        The sequence must be finite.
using reverse = fold_left::ret<flip::ret<cons>, empty_seq>;

END_YAML_NSP

#endif REVERSE_HPP_INCLUDED