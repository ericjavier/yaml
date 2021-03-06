#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/fold_right_1.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

TEST(fold_right_1, seq) {
  expect_yaml_is_same<std::integral_constant<int, 10>,
    fold_right_1::ret<plus, seq3>>();
}

TEST(fold_right_1, list) {
  expect_yaml_is_same<std::integral_constant<int, 10>,
    fold_right_1::ret<plus, lst3>>();
}