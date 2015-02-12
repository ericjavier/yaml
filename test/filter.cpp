#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/placeholders.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/filter.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using func = less::ret<_0, std::integral_constant<int, 3>>;
using expected = list<std::integral_constant<int, 0>,
  std::integral_constant<int, 1>,
  std::integral_constant<int, 2 >>;

TEST(filter, seq) {
  expect_same_seq<expected, filter::ret<func, seq3>>();
}

TEST(filter, list) {
  expect_same_seq<expected, filter::ret<func, lst3>>();
}