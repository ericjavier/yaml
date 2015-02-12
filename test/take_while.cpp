#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/take_while.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using expected = list<
  std::integral_constant<int, 0>,
  std::integral_constant<int, 1>>;

using pred = less::ret<_0, std::integral_constant<int, 2>>;

TEST(take_while, seq) {
  expect_same_seq<expected, take_while::ret<pred, seq3>>();
}

TEST(take_while, list) {
  expect_same_seq<expected, take_while::ret<pred, lst3>>();
}