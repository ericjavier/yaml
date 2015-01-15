#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/take.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using result = list<
  std::integral_constant<int, 0>,
  std::integral_constant<int, 1>>;

TEST(take, seq) {
  expect_same_seq<result,
    take_tmpl<std::integral_constant<std::size_t, 2>, seq3>::type>();
}

TEST(take, list) {
  expect_same_seq<result,
    take_tmpl<std::integral_constant<std::size_t, 2>, lst3>::type>();
}