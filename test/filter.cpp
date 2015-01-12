#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/placeholders.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/filter.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using func = apply<less, _0, std::integral_constant<int, 3>>::type;

TEST(filter, seq) {
  using exp = list<std::integral_constant<int, 0>,
    std::integral_constant<int, 1>,
    std::integral_constant<int, 2>>;

  expect_same_seq<exp, filter_tmpl<func, seq3>::type>();
}

TEST(filter, list) {
  using exp = list<std::integral_constant<int, 0>,
    std::integral_constant<int, 1>,
    std::integral_constant<int, 2>>;

  expect_same_seq<exp, filter_tmpl<func, lst3>::type>();
}