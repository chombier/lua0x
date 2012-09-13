#include "state.h"

#include <lua5.1/lua.hpp>

namespace lua {


  state::state() : impl( lua_open() )  { }
  
  state::~state() { lua_close( impl ); }
  
  state::operator lua_State*() const { return impl; }
  
   int state::string(const std::string& s) const {
    return luaL_dostring( *this, s.c_str() );
  }

  int state::file(const std::string& filename) const {
    return luaL_dofile( *this, filename.c_str() );
  }
  
  void state::libs() const{
    luaL_openlibs( *this );
  }
  
  std::string state::error(int err) const {
    std::string res;
    if( err ) {
      res = lua_tostring( *this, -1);
    }

    return res;
  }
  
}
