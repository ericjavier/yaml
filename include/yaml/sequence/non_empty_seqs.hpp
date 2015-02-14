#ifndef NON_EMPTY_SEQS_IMPLEMENTED
#define NON_EMPTY_SEQS_IMPLEMENTED

#include <yaml/config.hpp>
#include <yaml/core.hpp>
#include <yaml/sequence/sequence_def.hpp>
#include <yaml/sequence/fold_right.hpp>

BEGIN_YAML_NSP

BEGIN_DETAIL_NSP

template<typename S> class non_empty_seqs_tmpl {

  template<typename> struct impl;

  template<> struct impl<empty_seq> {
    using type = empty_seq;
  };

  template<typename H, typename R> struct impl<seq<H, R>> {

    template<typename Y, typename R> struct f_tmpl {
      using type = cons::ret<Y, cons::ret<cons::ret<H, Y> , R>>;
    };

    using f = make_curried_t<f_tmpl>;

    using type = cons::ret<seq<H, empty_seq>,
      fold_right::ret<f, empty_seq, impl<force_t<R>>>>;

  };

public:

  using type = typename impl<force_t<S>>::type;

};

END_DETAIL_NSP

/// brief Returns the list of all subsequences of the argument,
///       except for the empty list.
using non_empty_seqs = make_curried_t<DETAIL_NSP_REF non_empty_seqs_tmpl>;

END_YAML_NSP

#endif NON_EMPTY_SEQS_IMPLEMENTED