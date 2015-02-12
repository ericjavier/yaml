#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/head.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

TEST(head, seq) {
  expect_yaml_is_same<t<1>, head::ret<seq1>>();
  expect_yaml_is_same<t<4>, head::ret<seq2>>();
}

TEST(head, list) {
  expect_yaml_is_same<t<1>, head::ret<lst1>>();
  expect_yaml_is_same<t<4>, head::ret<lst2>>();
}