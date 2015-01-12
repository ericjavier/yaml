#include <gtest\gtest.h>
#include <yaml\config.hpp>
#include <yaml\detail\cond.hpp>
#include <yaml\sequence\is_same_seq.hpp>
#include "test_utils.hpp"

using namespace std;
using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(is_same_seq, true) {
  expect_std_true_type<is_same_seq_tmpl<seq1, lst1>::type>();
  expect_std_true_type<is_same_seq_tmpl<seq2, lst2>::type>();
}

TEST(is_same_seq, false) {
  expect_std_false_type<is_same_seq_tmpl<seq1, lst2>::type>();
  expect_std_false_type<is_same_seq_tmpl<seq2, lst1>::type>();
}