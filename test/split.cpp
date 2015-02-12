#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/split.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using taked_expected = list<
  std::integral_constant<int, 0>,
  std::integral_constant<int, 1 >> ;

using droped_expected = list<
  std::integral_constant<int, 2>,
  std::integral_constant<int, 3>,
  std::integral_constant<int, 4>>;


TEST(split, seq) {
  using actual = split::ret<std::integral_constant<std::size_t, 2>, seq3>;
  expect_same_seq<taked_expected, actual::first_type>();
  expect_same_seq<droped_expected, actual::second_type>();
}

TEST(split, list) {
  using actual = split::ret<std::integral_constant<std::size_t, 2>, lst3>;
  expect_same_seq<taked_expected, actual::first_type>();
  expect_same_seq<droped_expected, actual::second_type>();
}