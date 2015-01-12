#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/append.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(append, list_seq) {
  using exp = list<t<1>, t<2>, t<3>, t<4>, t<4>, t<3>, t<2>, t<1>>;
  expect_same_seq<exp, append_tmpl<lst1, seq2>::type>();
}

TEST(append, seq_list) {
  using exp = list<t<1>, t<2>, t<3>, t<4>, t<4>, t<3>, t<2>, t<1>>;
  expect_same_seq<exp, append_tmpl<seq1, lst2>::type>();
}