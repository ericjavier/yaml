#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/take.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using expected = list<
  std::integral_constant<int, 0>,
  std::integral_constant<int, 1>>;

TEST(take, seq) {
  expect_same_seq<expected,
    take::ret<std::integral_constant<std::size_t, 2>, seq3>>();
}

TEST(take, list) {
  expect_same_seq<expected,
    take::ret<std::integral_constant<std::size_t, 2>, lst3>>();
}