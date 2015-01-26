#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/placeholders.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/find_index.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using func = apply<less, std::integral_constant<int, 3>>::type;
using expected = std::integral_constant<std::size_t, 4>;

TEST(find_index, seq) {
  expect_yaml_is_same<expected, find_index_tmpl<func, seq3>::type>();
}

TEST(find_index, list) {
  expect_yaml_is_same<expected, find_index_tmpl<func, lst3>::type>();
}