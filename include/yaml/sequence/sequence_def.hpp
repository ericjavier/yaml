#ifndef SEQUENCE_FWD_HPP_INCLUDED
#define SEQUENCE_FWD_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>

BEGIN_YAML_NSP

template<typename H, typename R> struct seq {
  using type = seq<H, R>;
};

struct empty_seq {
  using type = empty_seq;
};

using cons = curried_func_t<seq>;

END_YAML_NSP

#endif SEQUENCE_FWD_HPP_INCLUDED