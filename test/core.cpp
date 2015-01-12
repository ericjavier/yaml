#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/core.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(initial_state, create) {
  expect_std_is_same<ls<ph<0>>, initial_placeholders<std::plus>::type>();
  expect_std_is_same<ls<ph<0>, ph<1>>,
    initial_placeholders<std::is_same>::type>();
  expect_std_is_same<ls<ph<0>, ph<1>, ph<2>, ph<3>, ph<4>>,
    initial_placeholders<five_argument_template>::type>();
  expect_std_is_same<
    ls<ph<0>, ph<1>, ph<2>, ph<3>, ph<4>, ph<5>, ph<6>, ph<7>, ph<8>, ph<9>>,
    initial_placeholders<ten_argument_template>::type>();
}

TEST(create_curried_function, case_one) {
  using res = create_curried_func<std::is_same>::type;
  using exp = curried_func<
    std::is_same,
    curried_func_state<2, 2, ph<0>, ph<1>>>;
  expect_std_is_same<exp, res>();
}

TEST(create_curried_function, case_two) {
  using res = create_curried_func<five_argument_template>::type;
  using exp = curried_func<
    five_argument_template,
    curried_func_state<5, 5, ph<0>, ph<1>, ph<2>, ph<3>, ph<4>>>;
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

TEST(next_state, transitions) {
  using res1 = next_state<curried_func_state<3, 3, ph<0>, ph<1>, ph<2>>,
    form_args<3, 2, ph<0>, t<0>, ph<1>>>::type;
  using exp1 = curried_func_state<3, 2, ph<0>, t<0>, ph<1>>;
  expect_std_is_same<exp1, res1>();

  using res2 = next_state<res1, form_args<2, 2, ph<1>, ph<0>>>::type;
  using exp2 = curried_func_state<3, 2, ph<1>, t<0>, ph<0>>;
  expect_std_is_same<exp2, res2>();

  using res3 = next_state<res2, form_args<2, 1, t<1>, ph<0>>>::type;
  using exp3 = curried_func_state<3, 1, ph<0>, t<0>, t<1>>;
  expect_std_is_same<exp3, res3>();

  using res4 = next_state<res3, form_args<1, 0, t<2>>>::type;
  using exp4 = curried_func_state<3, 0, t<2>, t<0>, t<1>>;
  expect_std_is_same<exp4, res4>();
}

TEST(apply_currying, case_one) {
  using f0 = create_curried_func<std::is_same>::type;
  using res = apply<f0, t<0>, t<0>>::type;
  expect_std_is_same<std::true_type, res>();
  //using res = apply<f1, t<0>>::type;
  //expect_std_is_same<std::true_type, res>();
}

TEST(apply_currying, case_two) {
  using f0 = create_curried_func<std::is_same>::type;
  using f1 = apply<f0, t<0>>::type;
  using res1 = apply<f1, t<0>>::type;
  using res2 = apply<f1, t<1>>::type;
  expect_std_true_type<res1>();
  expect_std_false_type<res2>();
}

