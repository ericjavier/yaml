#ifndef SEQUENCE_HPP_INCLUDED
#define SEQUENCE_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>

BEGIN_YAML_NSP

/// \brief Sequence definition
template<typename H, typename R> struct seq { 
  using type = seq<H, R>;
};

/// \brief Empty sequence definition
struct empty_seq {
  using type = empty_seq;
};

BEGIN_DETAIL_NSP

template<typename SL, typename SR> class is_same_seq { 

  template<typename, typename> struct impl : std::false_type { };

  template<> struct impl<empty_seq, empty_seq> : std::true_type { };

  template<typename HL, typename RL, typename HR, typename RR>
  struct impl<seq<HL, RL>, seq<HR, RR>> : std::integral_constant<bool, 
    is_same<HL, RL>::value &&
    impl<typename force<RL>::type, typename force<RR>::type>::value> { };

  using left = typename force<SL>::type;
  using right = typename force<SR>::type;

public:

  using type = typename impl<left, right>::type;

};

END_DETAIL_NSP

using is_same_seq = create_curried_func<DETAIL_NSP_REF is_same_seq>::type;



END_YAML_NSP

#endif SEQUENCE_HPP_INCLUDED