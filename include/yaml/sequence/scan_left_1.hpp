#ifndef SCAN_LEFT_1_HPP_INCLUDED
#define SCAN_LEFT_1_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\sequence\sequence_def.hpp>
#include <yaml\sequence\scan_left.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename S> class scan_left_1_tmpl { 

  template<typename S> struct impl;

  template<typename H, typename R> struct impl<seq<H, R>>
    : public scan_left_tmpl<F, H, force_t<R>> { };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

using scan_left_1 = curried_func_t<DETAIL_NSP_REF scan_left_1_tmpl>;

END_YAML_NSP

#endif SCAN_LEFT_1_HPP_INCLUDED