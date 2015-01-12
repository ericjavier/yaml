#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\sequence\sequence_def.hpp>

BEGIN_YAML_NSP

template<typename...> struct list;

template<typename H, typename... R>
struct list<H, R...> {
  using type = seq<H, list<R...>>;
};

template<> struct list<> {
  using type = empty_seq;
};

END_YAML_NSP

#endif LIST_HPP_INCLUDED