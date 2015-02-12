#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/concat.hpp>

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

using expected = list<t<1>, t<2>, t<1>, t<2>, t<3>, t<1>, t<2>, t<3>, t<4>>;

TEST(concat, case_one) {
  expect_same_seq<expected, concat::ret<args1>>();
}

TEST(concat, case_two) {
  expect_same_seq<expected, concat::ret<args2>>();
}