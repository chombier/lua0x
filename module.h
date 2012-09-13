#ifndef LUA_MODULE_H
#define LUA_MODULE_H

#include <lua5.1/lua.hpp>
#include <luabind/luabind.hpp>
#include <luabind/tag_function.hpp>

#include <lua0x/meta.h>

namespace lua0x {

  class module {
    const std::string name;
  public:
    typedef std::map< std::string, luabind::scope > scope_type;
    
    // declare a lua module with (global) name @name
    module( const std::string& name );
    
    // binds c++ function @f to lua module member @fun_name. calls to
    // this function may be chained.
    template<class F>
    const module& operator()(const char* fun_name, const F& f) const {
      typedef meta::func_type<F> func_type;

      // register std::function object type while we're at it
      luabind::class_< std::function<func_type> >( typeid(func_type).name() )
	.def("__call", &std::function<func_type>::operator());

      // wrap the function object
      std::function< func_type > fun = f;

      // concatenate scope with function declaration
      scope[name].operator,
	( luabind::def( fun_name, luabind::tag_function< func_type >( std::move(fun)) ) );
      
      return *this;
    }


    // initializes stuff: call this after the lua interpreter is
    // started. then, load cpp modules from lua side with:
    // cpp.load('my_module') 
    static void init(lua_State* L, const char* name = "cpp");
    
  private:
    static scope_type scope;

    static void load(const scope_type::value_type& x, lua_State* L);
  };
  
}


#endif
