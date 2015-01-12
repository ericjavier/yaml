#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/force.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(force, having_type) {
  expect_std_is_same<std::true_type, force<std::is_same<int, int>>::type>();
  expect_std_is_same<std::integral_constant<int, 0>,
    force<std::integral_constant<int, 0>>::type>();
}

TEST(force, not_having_type) {
  expect_std_is_same<std::plus<int>, force<std::plus<int>>::type>();
  expect_std_is_same<int, force<int>::type>();
}