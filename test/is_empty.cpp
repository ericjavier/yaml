#include <gtest\gtest.h>
#include <yaml\config.hpp>
#include <yaml\detail\cond.hpp>
#include <yaml\sequence\is_empty.hpp>
#include "test_utils.hpp"

using namespace std;
using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(is_empty, empty) {
  expect_yaml_is_same<std::true_type, is_empty_tmpl<list<>>::type>();
  expect_yaml_is_same<std::true_type, is_empty_tmpl<empty_seq>::type>();
}

TEST(is_empty, not_empty) {
  expect_yaml_is_same<std::false_type, is_empty_tmpl<lst1>::type>();
  expect_yaml_is_same<std::false_type, is_empty_tmpl<seq2>::type>();
}