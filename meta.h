#ifndef LUA_META_H
#define LUA_META_H

namespace lua {

  namespace meta {

    template<class A>
    struct helper {
      typedef A type;
    };

    // extract function type from function object operator()
    template<class Ret, class C, class ... Args>
    helper< Ret(Args...) > get_func_type( Ret (C::*)( Args ... ) const  );
    

    template<class F>
    using func_type = typename decltype( get_func_type(&F::operator()) )::type;
    
  }
}


#endif
