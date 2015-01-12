#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/have_type.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;


TEST(have_type, having_type) {
  expect_std_true_type<have_type_t<std::is_same<int, int>>>();
  expect_std_true_type<have_type_t<std::integral_constant<int, 0>>>();
}

TEST(have_type, not_having_type) {
  expect_std_false_type<have_type_t<std::plus<int>>>();
  expect_std_false_type<have_type_t<int>>();
}

