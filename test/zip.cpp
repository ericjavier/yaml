#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/zip.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using expected = list<
  pair_t<std::integral_constant<int, 0>, t<4>>,
  pair_t<std::integral_constant<int, 1>, t<3>>,
  pair_t<std::integral_constant<int, 2>, t<2>>, 
  pair_t<std::integral_constant<int, 3>, t<1>>>;

TEST(zip_with, seq_lst) {
  using result = apply<zip, seq3, lst2>::type;
  expect_same_seq<expected, result>();
}

TEST(zip_with, lst_seq) {
  using result = apply<zip, lst3, seq2>::type;
  expect_same_seq<expected, result>();
}