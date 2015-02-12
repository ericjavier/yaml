#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/append.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using expected = list<t<1>, t<2>, t<3>, t<4>, t<4>, t<3>, t<2>, t<1>>;

TEST(append, list_seq) {  
  expect_same_seq<expected, append::ret<lst1, seq2>>();
}

TEST(append, seq_list) {
  expect_same_seq<expected, append::ret<seq1, lst2>>();
}