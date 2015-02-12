#include <gtest/gtest.h>
#include <yaml/config.hpp>
#include <yaml/detail/placeholders.hpp>
#include <yaml/sequence/repeat.hpp>
#include <yaml/sequence/take.hpp>

#include "test_utils.hpp"

using namespace YAML_NSP;

using repeating = repeat::ret<t<0>>;

TEST(repeat, taking_0) {
  using expected = empty_seq;
  expect_same_seq<expected, 
    take::ret<std::integral_constant<std::size_t, 0>, repeating>>();
}

TEST(repeat, taking_3) {
  using expected = list<t<0>, t<0>, t<0>>;
  expect_same_seq<expected, 
    take::ret<std::integral_constant<std::size_t, 3>, repeating>>();
}

TEST(repeat, taking_9) {
  using expected = list<t<0>, t<0>, t<0>, t<0>, t<0>, t<0>, t<0>, t<0>, t<0>>;
  expect_same_seq<expected, 
    take::ret<std::integral_constant<std::size_t, 9>, repeating>>();
}