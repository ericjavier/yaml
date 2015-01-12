#ifndef DETAIL_PLACEHOLDERS_HPP_INCLUDED
#define DETAIL_PLACEHOLDERS_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/detail/force.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

/// \brief A simple placeholder templated on position.
template<std::size_t P> struct ph { };

END_DETAIL_NSP

using _0 = DETAIL_NSP_REF ph<0>;

END_YAML_NSP

#endif DETAIL_PLACEHOLDERS_HPP_INCLUDED