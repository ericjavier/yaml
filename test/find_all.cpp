#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/placeholders.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/find_all.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using func = apply<less, std::integral_constant<int, 2>>::type;
using expected = list<
  std::integral_constant<int, 3>,
  std::integral_constant<int, 4>>;

TEST(find_all, seq) {
  expect_same_seq<expected, find_all_tmpl<func, seq3>::type>();
}

TEST(find_all, list) {
  expect_same_seq<expected, find_all_tmpl<func, lst3>::type>();
}