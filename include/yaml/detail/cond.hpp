#ifndef DETAIL_COND_HPP
#define DETAIL_COND_HPP

#include <yaml/config.hpp>
#include <yaml/detail/force.hpp>

#include <type_traits>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

/// \brief Provides if-then-else functionality.
template<typename If, typename Then, typename Else> class cond {

  template<typename, typename, typename> struct impl;

  template<typename Then, typename Else>
  struct impl<std::true_type, Then, Else> {
    using type = typename force<Then>::type;
  };

  template<typename Then, typename Else>
  struct impl<std::false_type, Then, Else> {
    using type = typename force<Else>::type;
  };

public:

  using type = typename impl<typename force<If>::type, Then, Else>::type;

};

END_DETAIL_NSP

END_YAML_NSP

#endif DETAIL_COND_HPP