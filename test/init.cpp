#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/init.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

TEST(init, seq) {
  using exp1 = list<t<1>, t<2>, t<3>>;
  using exp2 = seq<t<4>, seq<t<3>, seq<t<2>, empty_seq>>>;

  expect_same_seq<exp1, init::ret<seq1>>();
  expect_same_seq<exp2, init::ret<seq2>>();
}

TEST(init, list) {
  using exp1 = seq<t<1>, seq<t<2>, seq<t<3>, empty_seq>>>;
  using exp2 = list<t<4>, t<3>, t<2>>;

  expect_same_seq<exp1, init::ret<lst1>>();
  expect_same_seq<exp2, init::ret<lst2>>();
}