#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/intersperse.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using expected1 = list<t<1>, void, t<2>, void, t<3>, void, t<4>>;
using expected2 = list<t<4>, void, t<3>, void, t<2>, void, t<1>>;

TEST(intersperse, seq) {
  expect_same_seq<expected1, intersperse::ret<void, seq1>>();
  expect_same_seq<expected2, intersperse::ret<void, seq2>>();
}

TEST(intersperse, list) {
  expect_same_seq<expected1, intersperse::ret<void, seq1>>();
  expect_same_seq<expected2, intersperse::ret<void, seq2>>();
}