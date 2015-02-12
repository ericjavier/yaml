#ifndef IS_EMPTY_HPP_INLCUDED
#define IS_EMPTY_HPP_INLCUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S> class is_empty_tmpl {

  template<typename> struct impl;

  template<typename H, typename R>
  struct impl<seq<H, R>> : public std::false_type { };

  template<> struct impl<empty_seq> : public std::true_type { };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Test whether a sequence is empty.
using is_empty = make_curried_t<DETAIL_NSP_REF is_empty_tmpl>;

END_YAML_NSP

#endif IS_EMPTY_HPP_INLCUDED