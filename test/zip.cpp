#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/zip.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using expected = list<
  pair<std::integral_constant<int, 0>, t<4>>,
  pair<std::integral_constant<int, 1>, t<3>>,
  pair<std::integral_constant<int, 2>, t<2>>, 
  pair<std::integral_constant<int, 3>, t<1>>>;

TEST(zip, seq_lst) {
  using result = zip::ret<seq3, lst2>;
  expect_same_seq<expected, result>();
}

TEST(zip, lst_seq) {
  using result = zip::ret<lst3, seq2>;
  expect_same_seq<expected, result>();
}