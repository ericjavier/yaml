#include <gtest\gtest.h>
#include <yaml\config.hpp>
#include <yaml\detail\cond.hpp>
#include <yaml\sequence\head.hpp>
#include "test_utils.hpp"

using namespace std;
using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(head, seq) {
  expect_yaml_is_same<t<1>, head_tmpl<seq1>::type>();
  expect_yaml_is_same<t<4>, head_tmpl<seq2>::type>();
}

TEST(head, list) {
  expect_yaml_is_same<t<1>, head_tmpl<lst1>::type>();
  expect_yaml_is_same<t<4>, head_tmpl<lst2>::type>();
}