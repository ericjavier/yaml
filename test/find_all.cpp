#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/placeholders.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/find_all.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using func = less::ret<std::integral_constant<int, 2>>;
using expected = list<
  std::integral_constant<int, 3>,
  std::integral_constant<int, 4>>;

TEST(find_all, seq) {
  expect_same_seq<expected, find_all::ret<func, seq3>>();
}

TEST(find_all, list) {
  expect_same_seq<expected, find_all::ret<func, lst3>>();
}