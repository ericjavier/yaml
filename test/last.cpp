#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/last.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

TEST(last, seq) {
  expect_yaml_is_same<t<4>, last::ret<seq1>>();
  expect_yaml_is_same<t<1>, last::ret<seq2>>();
}

TEST(last, list) {
  expect_yaml_is_same<t<4>, last::ret<lst1>>();
  expect_yaml_is_same<t<1>, last::ret<lst2>>();
}