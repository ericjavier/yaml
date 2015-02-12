#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/intercalate.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using args1 = list<
  list<t<1>, t<2>>,
  list<t<1>, t<2>, t<3>>,
  list<t<1>, t<2>, t<3>, t<4>>>;

using args2 = list<
  list<t<1>, t<2>, t<1>, t<2>>,
  list<t<3>, t<1>, t<2>>,
  list<t<3>, t<4>>>;

using expected1 = list<
  t<1>, t<2>, t<0>, t<1>, t<2>, t<3>, t<0>, t<1>, t<2>, t<3>, t<4>>;
using expected2 = list<
  t<1>, t<2>, t<1>, t<2>, t<0>, t<3>, t<1>, t<2>, t<0>, t<3>, t<4>>;

TEST(intercalate, case_one) {
  expect_same_seq<expected1, intercalate::ret<list<t<0>>, args1>>();
}

TEST(intercalate, case_two) {
  expect_same_seq<expected2, intercalate::ret<seq<t<0>, empty_seq>, args2>>();
}