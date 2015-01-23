#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/scan_left_1.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using expected = list<
  std::integral_constant<int, 0>,
  std::integral_constant<int, 1>,
  std::integral_constant<int, 3>,
  std::integral_constant<int, 6>,
  std::integral_constant<int, 10>>;

TEST(scan_left_1, seq) {
  expect_same_seq<expected, scan_left_1_tmpl<plus, seq3>::type>();
}

TEST(scan_left_1, list) {
  expect_same_seq<expected, scan_left_1_tmpl<plus, lst3>::type>();
}