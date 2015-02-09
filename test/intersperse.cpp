#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/intersperse.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;
using namespace DETAIL_NSP;

using expected1 = list<t<1>, void, t<2>, void, t<3>, void, t<4>>;
using expected2 = list<t<4>, void, t<3>, void, t<2>, void, t<1>>;

TEST(intersperse, seq) {
  expect_same_seq<expected1, intersperse_tmpl<void, seq1>::type>();
  expect_same_seq<expected2, intersperse_tmpl<void, seq2>::type>();
}

TEST(intersperse, list) {
  expect_same_seq<expected1, intersperse_tmpl<void, seq1>::type>();
  expect_same_seq<expected2, intersperse_tmpl<void, seq2>::type>();
}