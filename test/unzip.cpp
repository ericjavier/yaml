#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/unzip.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using arg = list<
  pair<std::integral_constant<int, 0>, t<4>>,
  pair<std::integral_constant<int, 1>, t<3>>,
  pair<std::integral_constant<int, 2>, t<2>>, 
  pair<std::integral_constant<int, 3>, t<1>>>;

using expected1 = list<
  std::integral_constant<int, 0>,
  std::integral_constant<int, 1>,
  std::integral_constant<int, 2>, 
  std::integral_constant<int, 3>>;

using expected2 = list<t<4>, t<3>, t<2>, t<1>>;


TEST(unzip, case_one) {
  using result = unzip::ret<arg>;
  expect_same_seq<expected1, result::first_type>();
  expect_same_seq<expected2, result::second_type>();
}
