#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/drop_while.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using expected = list<
  std::integral_constant<int, 2>,
  std::integral_constant<int, 3>,
  std::integral_constant<int, 4>>;

using pred = apply<less, _0, std::integral_constant<int, 2>>::type;

TEST(drop_while, seq) {
  expect_same_seq<expected, drop_while_tmpl<pred, seq3>::type>();
}

TEST(drop_while, list) {
  expect_same_seq<expected, drop_while_tmpl<pred, lst3>::type>();
}