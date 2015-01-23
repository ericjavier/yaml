#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/scan_left.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using expected = list<
  std::integral_constant<int, 0>,
  std::integral_constant<int, 0>,
  std::integral_constant<int, 1>,
  std::integral_constant<int, 3>,
  std::integral_constant<int, 6>,
  std::integral_constant<int, 10>>;

TEST(scan_left, seq) {
  expect_same_seq<expected,
    scan_left_tmpl<plus, std::integral_constant<int, 0>, seq3>::type>();
}

TEST(scan_left, list) {
  expect_same_seq<expected,
    scan_left_tmpl<plus, std::integral_constant<int, 0>, lst3>::type>();
}