#ifndef LUA_MODULE_H
#define LUA_MODULE_H

#include <lua5.1/lua.hpp>
#include <luabind/luabind.hpp>
#include <luabind/tag_function.hpp>

#include <lua0x/meta.h>
#include <utility>

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
    const module& operator()(const char* fun_name, F&& f) const {
      typedef meta::func_type< meta::decay<F> > func_type;
      
      // concatenate scope with function declaration
      push( luabind::def( fun_name, 
                          luabind::tag_function< func_type >( std::forward<F>(f) ) ) );
      
      return *this;
    }
    
    // initializes stuff: call this after the lua interpreter is
    // started. then, load cpp modules from lua side with:
    // cpp.load('my_module') 
    static int init(lua_State* L);
    
	  // loads the module in lua
	  void load(lua_State* L) const;
	   
  private:
    static scope_type scope;

    void push(const luabind::scope& ) const;    
	  static void load(const scope_type::value_type& x, lua_State* L);
  };
  
}


#endif
