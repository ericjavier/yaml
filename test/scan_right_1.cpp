#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/scan_right_1.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using result = list<
  std::integral_constant<int, 10>,
  std::integral_constant<int, 10>,
  std::integral_constant<int, 9>,
  std::integral_constant<int, 7>,
  std::integral_constant<int, 4>>;

TEST(scan_right_1, seq) {
  expect_same_seq<result, scan_right_1_tmpl<plus, seq3>::type>();
}

TEST(scan_right_1, list) {
  expect_same_seq<result, scan_right_1_tmpl<plus, lst3>::type>();
}