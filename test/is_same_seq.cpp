#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/sequence/is_same_seq.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

TEST(is_same_seq, true) {
  expect_std_true_type<is_same_seq::ret<seq1, lst1>>();
  expect_std_true_type<is_same_seq::ret<seq2, lst2>>();
}

TEST(is_same_seq, false) {
  expect_std_false_type<is_same_seq::ret<seq1, lst2>>();
  expect_std_false_type<is_same_seq::ret<seq2, lst1>>();
}