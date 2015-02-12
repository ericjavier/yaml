#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/drop.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using expected = list<
  std::integral_constant<int, 2>,
  std::integral_constant<int, 3>,
  std::integral_constant<int, 4>>;

TEST(drop, seq) {
  expect_same_seq<expected,
    drop::ret<std::integral_constant<std::size_t, 2>, seq3>>();
}

TEST(drop, list) {
  expect_same_seq<expected,
    drop::ret<std::integral_constant<std::size_t, 2>, lst3>>();
}