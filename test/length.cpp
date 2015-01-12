#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/length.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(length, seq) {
  expect_yaml_is_same<std::integral_constant<std::size_t, 4>, 
    length_tmpl<seq1>::type>();
  expect_yaml_is_same<std::integral_constant<std::size_t, 5>,
    length_tmpl<seq3>::type>();
}

TEST(length, list) {
  expect_yaml_is_same<std::integral_constant<std::size_t, 4>,
    length_tmpl<lst1>::type>();
  expect_yaml_is_same<std::integral_constant<std::size_t, 5>,
    length_tmpl<lst3>::type>();
}