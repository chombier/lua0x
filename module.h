#ifndef LUA_MODULE_H
#define LUA_MODULE_H

#include <lua5.1/lua.hpp>
#include <luabind/luabind.hpp>
#include <luabind/tag_function.hpp>

#include "meta.h"

namespace lua {

  class module {
    const std::string name;
  public:
    typedef std::map< std::string, luabind::scope > scope_type;
    
    // lua module with (global) name @name
    module( const std::string& name );
    
    // binds c++ function @f to lua module member @fun_name
    template<class F>
    const module& operator()(const char* fun_name, const F& f) const {
      typedef meta::func_type<F> func_type;
      
      std::function< func_type > fun = f;

      // register function object type while we're at it
      luabind::class_< std::function<func_type> >( typeid(func_type).name() )
	.def("__call", &std::function<func_type>::operator());
      
      // concatenate scope with function declaration
      scope[name].operator,
	( luabind::def( fun_name, luabind::tag_function< func_type >(fun) ) );
      
      return *this;
    }


    // initializes stuff. call this after the lua interpreter is
    // running. then, load cpp modules from lua side with:
    // cpp.load('my_module')  -- my_module
    static void init(lua_State* L, const char* name = "cpp");
    

  private:
    static scope_type scope;

    static void load(const scope_type::value_type& x, lua_State* L);
  };
  
}


#endif
