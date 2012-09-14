#ifndef LUA_META_H
#define LUA_META_H

#include <type_traits>

namespace lua0x {
  
  namespace meta {
    
    namespace impl {
      // type wrapper (because get_func_type can't return a function
      // type directly)
      template<class A>
      struct helper {
	typedef A type;
      };

      // extract function type from function object operator()
      template<class Ret, class C, class ... Args>
      helper< Ret(Args...) > get_func_type( Ret (C::*)( Args ... ) const  );
    }
    
    // extract the function type from a function class
    template<class F>
    using func_type = typename decltype( impl::get_func_type(&F::operator()) )::type;
    
    // shorthand for std::decay
    template<class F>
    using decay = typename std::decay<F>::type;

  }
}


#endif
