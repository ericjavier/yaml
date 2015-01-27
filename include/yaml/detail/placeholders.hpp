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
using _1 = DETAIL_NSP_REF ph<1>;
using _2 = DETAIL_NSP_REF ph<2>;
using _3 = DETAIL_NSP_REF ph<3>;
using _4 = DETAIL_NSP_REF ph<4>;
using _5 = DETAIL_NSP_REF ph<5>;
using _6 = DETAIL_NSP_REF ph<6>;
using _7 = DETAIL_NSP_REF ph<7>;
using _8 = DETAIL_NSP_REF ph<8>;
using _9 = DETAIL_NSP_REF ph<9>;

END_YAML_NSP

#endif DETAIL_PLACEHOLDERS_HPP_INCLUDED