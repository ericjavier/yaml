#ifndef IS_SAME_SEQ_HPP_INCLUDED
#define IS_SAME_SEQ_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\sequence\sequence_def.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename SL, typename SR> class is_same_seq_tmpl {

  template<typename, typename> struct impl : public std::false_type { };

  template<> struct impl<empty_seq, empty_seq> : public std::true_type { };

  template<typename HL, typename RL, typename HR, typename RR>
  struct impl<seq<HL, RL>, seq<HR, RR>>
    : public std::integral_constant<bool, is_same<HL, HR>::value &&
      impl<typename force<RL>::type, typename force<RR>::type>::value> { };

  using left = typename force<SL>::type;
  using right = typename force<SR>::type;

public:

  using type = typename impl<left, right>::type;

};

END_DETAIL_NSP

using is_same_seq = curried_func_t<DETAIL_NSP_REF is_same_seq_tmpl>;

END_YAML_NSP

#endif IS_SAME_SEQ_HPP_INCLUDED