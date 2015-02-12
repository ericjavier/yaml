#ifndef FOLD_RIGHT_1_HPP_INCLUDED
#define FOLD_RIGHT_1_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/fold_right.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename F, typename S> class fold_right_1_tmpl {

  template<typename> struct impl;

  template<typename H, typename R> struct impl<seq<H, R>>
    : public fold_right_tmpl<F, H, R> { };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

/// \brief Variant of 'fold_right' that has no starting value argument, and thus 
///        must be applied to non-empty lists.
using fold_right_1 = make_curried_t<DETAIL_NSP_REF fold_right_1_tmpl>;

END_YAML_NSP

#endif FOLD_RIGHT_1_HPP_INCLUDED