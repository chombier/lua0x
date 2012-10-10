#include "state.h"

#include <lua.hpp>
#include <cassert>

namespace lua0x {


	state::state(lua_State* impl) 
		: impl( impl )  { 

	}
  

	state::~state() { 
		
	}
	
	void state::open() {
		assert( !impl );
		impl = lua_open();
	}


	void state::close() {
		assert( impl );
		lua_close( impl );
		impl = 0;
	}

  
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


	state::raii_type state::raii() {
		return {*this};
	}
	
	state::raii_type::raii_type(state& s) : s(s) {
		s.open();
	}

	state::raii_type::~raii_type() {
		s.close();
	}

	
}
