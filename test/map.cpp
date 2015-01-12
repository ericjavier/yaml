#include <gtest\gtest.h>
#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\arithmetic.hpp>
#include <yaml\sequence\map.hpp>
#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using func = apply<plus, std::integral_constant<int, 1>>::type;

TEST(map, seq) {
  using exp = list<std::integral_constant<int, 1>,
    std::integral_constant<int, 2>,
    std::integral_constant<int, 3>,
    std::integral_constant<int, 4>,
    std::integral_constant<int, 5>> ;

  expect_same_seq<exp, map_tmpl<func, seq3>::type>();
}