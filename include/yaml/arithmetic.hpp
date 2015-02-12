#ifndef ARITHMETIC_HPP_INCLUDED
#define ARITHMETIC_HPP_INCLUDED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <type_traits>

#define DEFINE_ARITHM_FUNC(N, O) \
  BEGIN_YAML_NSP \
  BEGIN_DETAIL_NSP \
  template<typename L, typename R> class N##_tmpl { \
  template<typename L, typename R> struct impl; \
  template<typename LT, LT LV, typename RT, RT RV> \
  struct impl<std::integral_constant<LT, LV>, std::integral_constant<RT, RV>> { \
  using type = std::integral_constant<decltype(LV O RV), (LV O RV)>; }; \
  public: using type = typename impl<force_t<L>, force_t<R>>::type; }; \
  END_DETAIL_NSP \
  using N = make_curried_t<DETAIL_NSP_REF N##_tmpl>; \
  END_YAML_NSP \

DEFINE_ARITHM_FUNC(plus, +)
DEFINE_ARITHM_FUNC(minus, -)
DEFINE_ARITHM_FUNC(multiplies, *)
DEFINE_ARITHM_FUNC(divides, / )
DEFINE_ARITHM_FUNC(modulus, %)
DEFINE_ARITHM_FUNC(and, &&)
DEFINE_ARITHM_FUNC(bit_and, &)
DEFINE_ARITHM_FUNC(or, || )
DEFINE_ARITHM_FUNC(bit_or, | )
DEFINE_ARITHM_FUNC(bit_xor, ^)
DEFINE_ARITHM_FUNC(less, <)
DEFINE_ARITHM_FUNC(less_equals, <= )
DEFINE_ARITHM_FUNC(greater, >)
DEFINE_ARITHM_FUNC(greater_equals, >= )
DEFINE_ARITHM_FUNC(equals_to, == )
DEFINE_ARITHM_FUNC(not_equals_to, != )



BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename T> class not_tmpl {

  template<typename> struct impl;

  template<> struct impl<std::true_type> {
    using type = std::false_type;
  };

  template<> struct impl<std::false_type> {
    using type = std::true_type;
  };

public:

  using type = typename impl<force_t<T>>::type;

};

END_DETAIL_NSP

using not = make_curried_t<DETAIL_NSP_REF not_tmpl>;

END_YAML_NSP





#endif ARITHMETIC_HPP_INCLUDED