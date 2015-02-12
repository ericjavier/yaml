#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/fold_right.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

TEST(fold_right, seq) {
  expect_yaml_is_same<std::integral_constant<int, 10>,
    fold_right::ret<plus, std::integral_constant<int, 0>, seq3>>();
}

TEST(fold_right, list) {
  expect_yaml_is_same<std::integral_constant<int, 10>,
    fold_right::ret<plus, std::integral_constant<int, 0>, lst3>>();
}