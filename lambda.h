#ifndef LUA0X_LAMBDA_H
#define LUA0X_LAMBDA_H

#include <lua0x/func_type.h>
#include <luabind/tag_function.hpp>

namespace lua0x {

	// constructs a luabind::tag_function object automatically. useful
	// when dealing with lambdas.
	template<class F>
	auto lambda(F&& f) -> decltype( luabind::tag_function< func_type<F> >( std::forward<F>(f) ) )  {
		return { std::forward<F>(f) };
	}
	
}


#endif
