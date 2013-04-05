#ifndef LUA0X_FUNC_TYPE_H
#define LUA0X_FUNC_TYPE_H

#include <type_traits>

namespace lua0x {
    
	namespace impl {
		// type wrapper (because get_func_type can't return a function
		// type directly)
		template<class A>
		struct wrap {
			typedef A type;
		};

		// extract function type from function object operator()
		template<class Ret, class C, class ... Args>
		wrap< Ret(Args...) > get_func_type( Ret (C::*)( Args ... ) const  );

		// shorthand for std::decay
		template<class F>
		using decay = typename std::decay<F>::type;
	}
  
	
  
	// extract the function type from a function class
	template<class F>
	using func_type = typename decltype( impl::get_func_type(&impl::decay<F>::operator()) )::type;
    
}


#endif
