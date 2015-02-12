#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/reverse.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using expected = list<
  std::integral_constant<int, 4>,
  std::integral_constant<int, 3>,
  std::integral_constant<int, 2>,
  std::integral_constant<int, 1>,
  std::integral_constant<int, 0>>;

TEST(reverse, seq) {
  using result = reverse::ret<seq3>;
  expect_same_seq<expected, result>();
}

TEST(reverse, list) {
  using result = reverse::ret<lst3>;
  expect_same_seq<expected, result>();
}