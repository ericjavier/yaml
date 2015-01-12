#ifndef DETAIL_TEMPLATE_FITTING_HPP_INCLUDED
#define DETAIL_TEMPLATE_FITTING_HPP_INCLUDED

#include <yaml/config.hpp>
#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

/// \brief SFINAE usage to detect when a set of arguments fits a given template.
/// \!NOTE: only fitting lenght.
template<template<class...> class T, typename... Args>
std::true_type test_fitting(const T<Args...>*);

/// \brief FAILURE OVERLOAD
template<template<class...> class T, typename... Args>
std::false_type test_fitting(...);

/// \brief Helper to know when a set of arguments fits a given template.
template<template<class...> class T, typename... Args>
using fitting_t = decltype(test_fitting<T, Args...>(0));

END_DETAIL_NSP

END_YAML_NSP

#endif DETAIL_TEMPLATE_FITTING_HPP_INCLUDED