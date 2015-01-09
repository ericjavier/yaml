#include <gtest\gtest.h>
#include <yaml\config.hpp>
#include <yaml\detail\take_from_variadic.hpp>
#include "test_utils.hpp"

using namespace std;
using namespace YAML_NSP;
using namespace DETAIL_NSP;

TEST(take_from_variadic, case_one) {
  expect_std_is_same<int, take_from_variadic<0, int, long, short>::type>();
  expect_std_is_same<long, take_from_variadic<1, int, long, short>::type>();
  expect_std_is_same<short, take_from_variadic<2, int, long, short>::type>();
}