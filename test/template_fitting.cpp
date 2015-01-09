#include <gtest\gtest.h>
#include <yaml\config.hpp>
#include <yaml\detail\template_fitting.hpp>
#include <yaml\detail\placeholders.hpp>
#include "test_utils.hpp"

using namespace std;
using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(fitting, when_fits) {
  expect_std_true_type<fitting_t<std::is_same, int, long>>();
  expect_std_true_type<fitting_t<std::plus, int>>();
  expect_std_true_type<fitting_t<std::is_same, ph<0>, ph<1>>>();
}

TEST(fitting, when_not_fits) {
  expect_std_false_type<fitting_t<std::is_same, int>>();
  expect_std_false_type<fitting_t<std::plus, int, int>>();
  expect_std_false_type<fitting_t<std::is_same, ph<0>>>();
}