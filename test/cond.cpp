//#include <gtest/gtest.h>
//#include <yaml/config.hpp>
//#include <yaml/detail/cond.hpp>
//
//#include "test_utils.hpp"
//
//using namespace YAML_NSP;
//using namespace DETAIL_NSP;
//
//TEST(cond, then_case) {
//  expect_std_is_same<
//    cond<have_type_t<std::integral_constant<int, 0>>,
//    std::integral_constant<int, 0>,
//    std::integral_constant<int, 1>>::type,
//    std::integral_constant<int, 0>>();
//}
//
//TEST(cond, else_case) {
//  expect_std_is_same<
//    cond<have_type_t<std::plus<int>>,
//    inconditional_force_type_of<std::plus<int>>,
//    std::integral_constant<int, 0>>::type,
//    std::integral_constant<int, 0>>();
//}