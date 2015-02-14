#ifndef IS_SAME_SEQ_HPP_INCLUDED
#define IS_SAME_SEQ_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/arithmetic.hpp>
#include <yaml/sequence/sequence_def.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename SL, typename SR> class is_same_seq_tmpl {

  template<typename, typename> struct impl {
    using type = std::false_type;
  };
  
  template<> struct impl<empty_seq, empty_seq> {
    using type = std::true_type;
  };

  template<typename HL, typename RL, typename HR, typename RR>
  struct impl<seq<HL, RL>, seq<HR, RR>> {
    using type = and::ret<
      std::is_same<force_t<HL>, force_t<HR>>, 
      typename impl<force_t<RL>, force_t<RR>>::type>;
  };

public:

  using type = typename impl<force_t<SL>, force_t<SR>>::type;

};

END_DETAIL_NSP

using is_same_seq = make_curried_t<DETAIL_NSP_REF is_same_seq_tmpl>;

END_YAML_NSP

#endif IS_SAME_SEQ_HPP_INCLUDED