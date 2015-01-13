#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/fold_left_1.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(fold_left_1, seq) {
  expect_yaml_is_same<std::integral_constant<int, 10>,
    fold_left_1_tmpl<plus, seq3>::type>();
}

TEST(fold_left_1, list) {
  expect_yaml_is_same<std::integral_constant<int, 10>,
    fold_left_1_tmpl<plus, lst3>::type>();
}