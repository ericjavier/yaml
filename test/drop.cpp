#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/drop.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using result = list<
  std::integral_constant<int, 2>,
  std::integral_constant<int, 3>,
  std::integral_constant<int, 4>> ;

TEST(drop, seq) {
  expect_same_seq<result,
    drop_tmpl<std::integral_constant<std::size_t, 2>, seq3>::type>();
}

TEST(drop, list) {
  expect_same_seq<result,
    drop_tmpl<std::integral_constant<std::size_t, 2>, lst3>::type>();
}