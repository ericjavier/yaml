#include <gtest\gtest.h>
#include <yaml\config.hpp>
#include <yaml\sequence\init.hpp>
#include "test_utils.hpp"

using namespace std;
using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(init, seq) {
  using act1 = list<t<1>, t<2>, t<3>>;
  using act2 = seq<t<4>, seq<t<3>, seq<t<2>, empty_seq>>>;

  expect_same_seq<act1, init_tmpl<seq1>::type>();
  expect_same_seq<act2, init_tmpl<seq2>::type>();
}

TEST(init, list) {
  using act1 = seq<t<1>, seq<t<2>, seq<t<3>, empty_seq>>>;
  using act2 = list<t<4>, t<3>, t<2>>;

  expect_same_seq<act1, init_tmpl<lst1>::type>();
  expect_same_seq<act2, init_tmpl<lst2>::type>();
}