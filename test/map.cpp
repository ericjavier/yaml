#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/map.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using func = plus::ret<std::integral_constant<int, 1>>;
using expected = list<std::integral_constant<int, 1>,
  std::integral_constant<int, 2>,
  std::integral_constant<int, 3>,
  std::integral_constant<int, 4>,
  std::integral_constant<int, 5>>;

TEST(map, seq) {
  expect_same_seq<expected, map::ret<func, seq3>>();
}

TEST(map, list) {
  expect_same_seq<expected, map::ret<func, lst3>>();
}