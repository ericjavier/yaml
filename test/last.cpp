#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/last.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(last, seq) {
  expect_yaml_is_same<t<4>, last_tmpl<seq1>::type>();
  expect_yaml_is_same<t<1>, last_tmpl<seq2>::type>();
}

TEST(last, list) {
  expect_yaml_is_same<t<4>, last_tmpl<lst1>::type>();
  expect_yaml_is_same<t<1>, last_tmpl<lst2>::type>();
}