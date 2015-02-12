#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/arithmetic.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(initial_placeholders, create) {
  expect_std_is_same<ls<ph<0>>, initial_phs<std::plus>::type>();
  expect_std_is_same<ls<ph<0>, ph<1>>,
    initial_phs<std::is_same>::type>();
  expect_std_is_same<ls<ph<0>, ph<1>, ph<2>, ph<3>, ph<4>>,
    initial_phs<five_argument_template>::type>();
  expect_std_is_same<
    ls<ph<0>, ph<1>, ph<2>, ph<3>, ph<4>, ph<5>, ph<6>, ph<7>, ph<8>, ph<9>>,
    initial_phs<ten_argument_template>::type>();
}

TEST(make_state, case_one) {
  using act = make_state<std::is_same>::type;
  using exp = currying_state<2, 2, ph<0>, ph<1>>;
  expect_std_is_same<exp, act>();
}

TEST(make_curried_t, case_one) {
  using res = make_curried_t<std::is_same>;
  using exp = curried_t<std::is_same, currying_state<2, 2, ph<0>, ph<1>>>;
  expect_std_is_same<exp, res>();
}

TEST(make_curried_t, case_two) {
  using res = make_curried_t<five_argument_template>;
  using exp = curried_t<five_argument_template,
    currying_state<5, 5, ph<0>, ph<1>, ph<2>, ph<3>, ph<4>>>;
  expect_std_is_same<exp, res>();
}

TEST(formalize_args, case_one) {
  using res = formalize_args<5, t<0>, t<1>>::type;
  using exp = form_args<5, 3, t<0>, t<1>, ph<0>, ph<1>, ph<2>>;
  expect_std_is_same<exp, res>();
}

TEST(formalize_args, case_two) {
  using res = formalize_args<5, ph<0>, t<0>, t<1>>::type;
  using exp = form_args<5, 3, ph<0>, t<0>, t<1>, ph<1>, ph<2>>;
  expect_std_is_same<exp, res>();
}

TEST(formalize_args, case_three) {
  using res = formalize_args<
    10, ph<3>, t<0>, ph<2>, t<1>, ph<1>, ph<0>, t<2>> ::type;
  using exp = form_args<
    10, 7, ph<3>, t<0>, ph<2>, t<1>, ph<1>, ph<0>, t<2>, ph<4>, ph<5>, ph<6>>;
  expect_std_is_same<exp, res>();
}

TEST(formalize_args, case_four) {
  using res = formalize_args<2, t<0>, t<1>>::type;
  using exp = form_args<2, 0, t<0>, t<1>>;
  expect_std_is_same<exp, res>();
}

TEST(move_state, transitions) {
  using res1 = move_state<currying_state<3, 3, ph<0>, ph<1>, ph<2>>,
    form_args<3, 2, ph<0>, t<0>, ph<1>>>::type;
  using exp1 = currying_state<3, 2, ph<0>, t<0>, ph<1>>;
  expect_std_is_same<exp1, res1>();

  using res2 = move_state<res1, form_args<2, 2, ph<1>, ph<0>>>::type;
  using exp2 = currying_state<3, 2, ph<1>, t<0>, ph<0>>;
  expect_std_is_same<exp2, res2>();

  using res3 = move_state<res2, form_args<2, 1, t<1>, ph<0>>>::type;
  using exp3 = currying_state<3, 1, ph<0>, t<0>, t<1>>;
  expect_std_is_same<exp3, res3>();

  using res4 = move_state<res3, form_args<1, 0, t<2>>>::type;
  using exp4 = currying_state<3, 0, t<2>, t<0>, t<1>>;
  expect_std_is_same<exp4, res4>();
}

TEST(apply_currying, case_one) {
  using f0 = make_curried_t<std::is_same>;
  using res = f0::ret<t<0>, t<0>>;
  expect_std_is_same<std::true_type, res>();
}

TEST(apply_currying, case_two) {
  using f0 = make_curried_t<std::is_same>;
  using f1 = f0::ret<>;
  using res = f1::ret<t<0>, t<0>>;
  expect_std_is_same<std::true_type, res>();
}

TEST(apply_currying, case_three) {
  using f0 = make_curried_t<std::is_same>;
  using f1 = f0::ret<t<0>>;
  using res1 = f1::ret<t<0>>;
  using res2 = f1::ret<t<1>>;
  expect_std_true_type<res1>();
  expect_std_false_type<res2>();
}

TEST(apply_currying, case_four) {
  using f0 = make_curried_t<std::is_same>;
  using f1 = f0::ret<>;
  using f2 = f1::ret<t<0>>;
  using f3 = f2::ret<>;
  using res1 = f3::ret<t<0>>;
  using res2 = f3::ret<t<1>>;
  expect_std_true_type<res1>();
  expect_std_false_type<res2>();
}

TEST(flip, case_one) {
  using f = flip::ret<minus>;
  using expected = std::integral_constant<int, 3>;
  using result = f::ret<
    std::integral_constant<int, 4>,
    std::integral_constant<int, 7>>;
  expect_std_is_same<expected, result>();
}