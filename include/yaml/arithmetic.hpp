#ifndef ARITHMETIC_HPP_INCLUDED
#define ARITHMETIC_HPP_INCLUDED

#include <yaml\config.hpp>
#include <yaml\core.hpp>
#include <yaml\detail\force.hpp>
#include <type_traits>

#define DEFINE_ARITHM_FUNC(N, O) \
  BEGIN_YAML_NSP \
  BEGIN_DETAIL_NSP \
  template<typename L, typename R> class N { \
  template<typename L, typename R> struct impl; \
  template<typename LT, LT LV, typename RT, RT RV> \
  struct impl<std::integral_constant<LT, LV>, std::integral_constant<RT, RV>> { \
  using type = std::integral_constant<decltype(LV O RV), (LV O RV)>; }; \
  using left = typename force<L>::type; \
  using right = typename force<R>::type; \
  public: using type = typename impl<left, right>::type; }; \
  END_DETAIL_NSP \
  using N = curried_func_t<DETAIL_NSP_REF N>; \
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

#endif ARITHMETIC_HPP_INCLUDED