#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

#include <gtest/gtest.h>
#include <type_traits>
#include <string>

#include <yaml/core.hpp>
#include <yaml/list.hpp>
#include <yaml/sequence.hpp>

using YAML_NSP_REF list;
using YAML_NSP_REF seq;
using YAML_NSP_REF empty_seq;

template<typename Exp, typename Act> inline std::string log() {

  std::ostringstream os;
  os << "---------------------------------------------------------------------"
     << std::endl
     << "Exp: "
     << typeid(Exp).name()
     << std::endl
     << "Act: "
     << typeid(Act).name()
     << std::endl
     << "---------------------------------------------------------------------";

  return os.str();
}

template<typename Exp, typename Act> inline void expect_same_seq() {
  EXPECT_TRUE((typename YAML_NSP_REF DETAIL_NSP_REF
    is_same_seq_tmpl<Exp, Act>::type::value)) << log<Exp, Act>();
}

template<typename Exp, typename Act> inline void expect_yaml_is_same() {
  EXPECT_TRUE((YAML_NSP_REF is_same<Exp, Act>::value)) << log<Exp, Act>();
}

template<typename Exp, typename Act> inline void expect_std_is_same() {
  EXPECT_TRUE((std::is_same<Exp, Act>::value)) << log<Exp, Act>();
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

// test data
using seq1 = seq<t<1>, seq<t<2>, seq<t<3>, seq<t<4>, empty_seq>>>>;
using seq2 = seq<t<4>, seq<t<3>, seq<t<2>, seq<t<1>, empty_seq>>>>;
using seq3 = seq<std::integral_constant<int, 0>,
  seq<std::integral_constant<int, 1>,
    seq<std::integral_constant<int, 2>,
      seq<std::integral_constant<int, 3>,
        seq<std::integral_constant<int, 4>,
          empty_seq>>>>>;


using lst1 = list<t<1>, t<2>, t<3>, t<4>>;
using lst2 = list<t<4>, t<3>, t<2>, t<1>>;
using lst3 = list<std::integral_constant<int, 0>,
  std::integral_constant<int, 1>,
  std::integral_constant<int, 2>,
  std::integral_constant<int, 3>,
  std::integral_constant<int, 4>>;

#endif TEST_UTILS_HPP