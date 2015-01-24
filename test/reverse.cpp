#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/reverse.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using expected = list<
  std::integral_constant<int, 4>,
  std::integral_constant<int, 3>,
  std::integral_constant<int, 2>,
  std::integral_constant<int, 1>,
  std::integral_constant<int, 0>>;

TEST(reverse, seq) {
  using result = apply<reverse, seq3>::type;
  expect_same_seq<expected, result>();
}

TEST(reverse, list) {
  using result = apply<reverse, lst3>::type;
  expect_same_seq<expected, result>();
}