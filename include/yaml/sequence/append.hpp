#ifndef APPEND_HPP_INCLUDED
#define APPEND_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\sequence\sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename SL, typename SR> class append_tmpl {

  template<typename, typename> struct impl;

  template<typename SR> struct impl<empty_seq, SR> {
    using type = SR;
  };

  template<typename HL, typename RL, typename SR> struct impl<seq<HL, RL>, SR> {
    using type = seq<HL, impl<force_t<RL>, SR>>;
  };

public:

  using type = typename impl<force_t<SL>, force_t<SR>>::type;
};

using append = curried_func_t<DETAIL_NSP_REF append_tmpl>;

END_DETAIL_NSP

END_YAML_NSP

#endif APPEND_HPP_INCLUDED