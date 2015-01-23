#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/tail.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(tail, seq) {
  using exp1 = list<t<2>, t<3>, t<4>>;
  using exp2 = seq<t<3>, seq<t<2>, seq<t<1>, empty_seq>>>;
  
  expect_same_seq<exp1, tail_tmpl<seq1>::type>();
  expect_same_seq<exp2, tail_tmpl<seq2>::type>();
}

TEST(tail, list) {
  using exp1 = seq<t<2>, seq<t<3>, seq<t<4>, empty_seq>>>;
  using exp2 = list<t<3>, t<2>, t<1>>;

  expect_same_seq<exp1, tail_tmpl<lst1>::type>();
  expect_same_seq<exp2, tail_tmpl<lst2>::type>();
}