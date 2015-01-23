#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/zip_with.hpp>
#include <yaml/arithmetic.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using expected = list<
  std::integral_constant<int, 0>,
  std::integral_constant<int, 2>,
  std::integral_constant<int, 4>,
  std::integral_constant<int, 6>,
  std::integral_constant<int, 8>>;

TEST(zip_with, seq) {
  expect_same_seq<expected, zip_with_tmpl<YAML_NSP_REF plus, seq3, seq3>::type>();
}

TEST(zip_with, list) {
  expect_same_seq<expected, zip_with_tmpl<YAML_NSP_REF plus, lst3, lst3>::type>();
}