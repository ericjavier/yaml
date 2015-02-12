#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/placeholders.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/find_indices.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using func = less::ret<std::integral_constant<int, 2>>;
using expected = list<
  std::integral_constant<std::size_t, 3>,
  std::integral_constant<std::size_t, 4>>;

TEST(find_indices, seq) {
  expect_same_seq<expected, find_indices::ret<func, seq3>>();
}

TEST(find_indices, list) {
  expect_same_seq<expected, find_indices::ret<func, lst3>>();
}