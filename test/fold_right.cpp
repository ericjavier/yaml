#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/fold_right.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(fold_right, seq) {
  expect_yaml_is_same<std::integral_constant<int, 10>,
    fold_right_tmpl<plus, std::integral_constant<int, 0>, seq3>::type>();
}

TEST(fold_right, list) {
  expect_yaml_is_same<std::integral_constant<int, 10>,
    fold_right_tmpl<plus, std::integral_constant<int, 0>, lst3>::type>();
}