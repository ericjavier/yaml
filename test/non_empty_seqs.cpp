#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/non_empty_seqs.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using arg = list<t<1>, t<2>, t<3>>;
using expected = list<
  list<t<1>>,
  list<t<2>>,
  list<t<1>, t<2>>,
  list<t<3>>,
  list<t<1>, t<3>>,
  list<t<2>, t<3>>,
  list<t<1>, t<2>, t<3>>>;

TEST(non_empty_seqs, case_one) {  
  expect_same_seq<expected, non_empty_seqs::ret<arg>>();
}
