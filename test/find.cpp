#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/placeholders.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/find.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using func = less::ret<std::integral_constant<int, 3>>;
using expected = std::integral_constant<int, 4>;

TEST(find, seq) {
  expect_yaml_is_same<expected, find::ret<func, seq3>>();
}

TEST(find, list) {
  expect_yaml_is_same<expected, find::ret<func, lst3>>();
}