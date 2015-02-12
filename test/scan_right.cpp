#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/scan_right.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using expected = list<
  std::integral_constant<int, 10>,
  std::integral_constant<int, 10>,
  std::integral_constant<int, 9>,
  std::integral_constant<int, 7>,
  std::integral_constant<int, 4>,
  std::integral_constant<int, 0>>;

TEST(scan_right, seq) {
  expect_same_seq<expected,
    scan_right::ret<plus, std::integral_constant<int, 0>, seq3>>();
}

TEST(scan_right, list) {
  expect_same_seq<expected,
    scan_right::ret<plus, std::integral_constant<int, 0>, lst3>>();
}