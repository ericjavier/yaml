#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/index.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

TEST(index, seq) {
  expect_yaml_is_same<t<1>, index::ret<std::integral_constant<std::size_t, 0>,
    seq1>>();
  expect_yaml_is_same<t<3>, index::ret<std::integral_constant<std::size_t, 2>,
    seq1>>();
}

TEST(index, list) {
  expect_yaml_is_same<t<1>, index::ret<std::integral_constant<std::size_t, 0>,
    lst1>>();
  expect_yaml_is_same<t<3>, index::ret<std::integral_constant<std::size_t, 2>,
    lst1>>();
}