#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/placeholders.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/find_if.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using func = apply<less, std::integral_constant<int, 3>>::type;
using expected = std::integral_constant<int, 4>;

TEST(find_if, seq) {
  expect_yaml_is_same<expected, find_if_tmpl<func, seq3>::type>();
}

TEST(find_if, list) {
  expect_yaml_is_same<expected, find_if_tmpl<func, lst3>::type>();
}