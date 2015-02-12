#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/is_empty.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

TEST(is_empty, empty) {
  expect_yaml_is_same<std::true_type, is_empty::ret<list<>>>();
  expect_yaml_is_same<std::true_type, is_empty::ret<empty_seq>>();
}

TEST(is_empty, not_empty) {
  expect_yaml_is_same<std::false_type, is_empty::ret<lst1>>();
  expect_yaml_is_same<std::false_type, is_empty::ret<seq2>>();
}