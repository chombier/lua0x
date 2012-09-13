#include "module.h"

#include <stdexcept>
#include <iostream>

namespace lua0x {

  module::module( const std::string& name)
    : name(name) { 
    if( scope.find(name) != scope.end() ) {
      throw std::logic_error("module " + name + " already exists");
    }

  }


  void module::init(lua_State* L, const char* name ) {

      auto fun = [L](const std::string& name) {
	auto it = scope.find(name);
	
	if( it == scope.end() ) {
	  throw std::logic_error("no module named " + name );
	}
	
	load( *it, L );
      };
      
      module cpp(name);
      cpp("load", fun);
       
      // self-load 
      fun( name );
  }


  void module::load(const scope_type::value_type& x, lua_State* L) {
    std::cout << "loading module " << x.first << std::endl;
    luabind::module(L, x.first.c_str())[ x.second ];
  }
  
  module::scope_type module::scope;
  
}
