#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/arithmetic.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

#define TEST_ARITHM_FUNC(N, C, LT, LV, RT, RV, T, V) \
  TEST(N, C) { \
  using larg = std::integral_constant<LT, LV>; \
  using rarg = std::integral_constant<RT, RV>; \
  using exp = std::integral_constant<T, V>; \
  using act = N::ret<larg, rarg>; \
  expect_std_is_same<exp, act>(); } \
  
TEST_ARITHM_FUNC(plus, plus, int, -2, int, 3, int, 1)
TEST_ARITHM_FUNC(minus, minus, int, 6, int, 3, int, 3)
TEST_ARITHM_FUNC(bit_or, bit_or, int, 6, int, 3, int, 7)
TEST_ARITHM_FUNC(bit_and, bit_and, int, 6, int, 3, int, 2)
TEST_ARITHM_FUNC(bit_xor, bit_xor, int, 6, int, 3, int, 5)
TEST_ARITHM_FUNC(multiplies, multiplies, int, 2, int, 3, int, 6)
TEST_ARITHM_FUNC(less, less_with_lesser_at_left, int, 2, int, 3, bool, true)
TEST_ARITHM_FUNC(less, less_with_lesser_at_right, int, 7, int, 3, bool, false)
TEST_ARITHM_FUNC(less, less_with_equals, int, 3, int, 3, bool, false)
TEST_ARITHM_FUNC(greater, greater_with_lesser_at_left, int, 2, int, 3, bool, false)
TEST_ARITHM_FUNC(greater, greater_with_lesser_at_right, int, 7, int, 3, bool, true)
TEST_ARITHM_FUNC(greater, greater_with_equals, int, 3, int, 3, bool, false)
TEST_ARITHM_FUNC(less_equals, less_equals_with_lesser_at_left, int, 1, int, 3, bool, true)
TEST_ARITHM_FUNC(less_equals, less_equals_with_lesser_at_right, int, 6, int, 3, bool, false)
TEST_ARITHM_FUNC(less_equals, less_equals_with_equals, int, 3, int, 3, bool, true)
TEST_ARITHM_FUNC(not_equals_to, not_equals_to_with_equals, int, 3, int, 3, bool, false)
TEST_ARITHM_FUNC(not_equals_to, not_equals_to_with_differents, int, 6, int, 3, bool, true)
TEST_ARITHM_FUNC(equals_to, equals_to_with_equals, int, 3, int, 3, bool, true)
TEST_ARITHM_FUNC(equals_to, equals_to_with_differents, int, 6, int, 3, bool, false)
TEST_ARITHM_FUNC(greater_equals, greater_equals_with_lesser_at_left, int, 1, int, 3, bool, false)
TEST_ARITHM_FUNC(greater_equals, greater_equals_with_lesser_at_right, int, 3, int, 1, bool, true)
TEST_ARITHM_FUNC(greater_equals, greater_equals_with_equals, int, 3, int, 3, bool, true)
TEST_ARITHM_FUNC(and, and_between_2_trues, bool, true, bool, true, bool, true)
TEST_ARITHM_FUNC(and, and_between_false_and_true, bool, false, bool, true, bool, false)
TEST_ARITHM_FUNC(and, and_between_true_and_false, bool, true, bool, false, bool, false)
TEST_ARITHM_FUNC(and, and_between_2_falses, bool, false, bool, false, bool, false)
TEST_ARITHM_FUNC(or, or_between_2_trues, bool, true, bool, true, bool, true)
TEST_ARITHM_FUNC(or, or_between_false_and_true, bool, false, bool, true, bool, true)
TEST_ARITHM_FUNC(or, or_between_true_and_false, bool, true, bool, false, bool, true)
TEST_ARITHM_FUNC(or, or_between_2_falses, bool, false, bool, false, bool, false)

TEST(not, with_true) {
  expect_std_is_same<std::false_type, not::ret<std::true_type>>();
}

TEST(not, with_false) {
  expect_std_is_same<std::true_type, not::ret<std::false_type>>();
}