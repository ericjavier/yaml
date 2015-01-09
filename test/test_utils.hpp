#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <gtest\gtest.h>
#include <type_traits>

#include <yaml\core.hpp>

template<typename Exp, typename Act> inline void expect_yaml_is_same() {
  EXPECT_TRUE((YAML_NSP_REF is_same<Exp, Act>::value));
}

template<typename Exp, typename Act> inline void expect_std_is_same() {
  EXPECT_TRUE((std::is_same<Exp, Act>::value));
}

template<typename Act> inline void expect_std_true_type() {
  expect_std_is_same<std::true_type, Act>();
}

template<typename Act> inline void expect_std_false_type() {
  expect_std_is_same<std::false_type, Act>();
}

// other stuff

template<typename T> struct inconditional_force_type_of {
  using type = typename T::type;
};

template<
  typename, // 0
  typename, // 1
  typename, // 2
  typename, // 3
  typename> // 4
struct five_argument_template;

template<
  typename, // 0
  typename, // 1
  typename, // 2
  typename, // 3
  typename, // 4
  typename, // 5
  typename, // 6
  typename, // 7
  typename, // 8
  typename> // 9
struct ten_argument_template;

//! used for fast generation of types
template<int> struct t;

#endif TEST_UTILS_HPP