#ifndef DETAIL_HAVE_TYPE_HPP_INCLUDED
#define DETAIL_HAVE_TYPE_HPP_INCLUDED

#include <yaml\config.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

/// \brief SFINAE helper functions.
template<typename T> std::true_type test_type(const typename T::type*);
template<typename T> std::false_type test_type(...);

/// \brief 'std::true_type' if 'T' have a 'type', 'std::false_type' otherwise.
template<typename T> using have_type_t = decltype(test_type<T>(0));

END_DETAIL_NSP

END_YAML_NSP

#endif DETAIL_HAVE_TYPE_HPP_INCLUDED