#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/length.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(length, seq) {
  expect_yaml_is_same<std::integral_constant<std::size_t, 4>, 
    length::ret<seq1>>();
  expect_yaml_is_same<std::integral_constant<std::size_t, 5>,
    length::ret<seq3>>();
}

TEST(length, list) {
  expect_yaml_is_same<std::integral_constant<std::size_t, 4>,
    length::ret<lst1>>();
  expect_yaml_is_same<std::integral_constant<std::size_t, 5>,
    length::ret<lst3>>();
}