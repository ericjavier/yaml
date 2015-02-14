#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/transpose.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using arg1 = list<
  list<t<1>, t<2>, t<3>>,
  list<t<4>, t<5>, t<6>>>;

using arg2 = list<
  list<t<1>, t<2>>,
  list<t<3>, t<4>>,
  list<t<5>, t<6>>>;

using expected1 = list<
  list<t<1>, t<4>>,
  list<t<2>, t<5>>,
  list<t<3>, t<6>>>;

using expected2 = list<
  list<t<1>, t<3>, t<5>>,
  list<t<2>, t<4>, t<6>>>;

TEST(transpose, case_one) {
  expect_same_seq<expected1, transpose::ret<arg1>>();
}

TEST(transpose, case_two) {
  expect_same_seq<expected2, transpose::ret<arg2>>();
}

TEST(transpose, case_three) {
 expect_same_seq<arg1, transpose::ret<transpose::ret<arg1>>>();
}

TEST(transpose, case_four) {
  expect_same_seq<arg2, transpose::ret<transpose::ret<arg2>>>();
}