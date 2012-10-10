#ifndef LUA_STATE_H
#define LUA_STATE_H

#include <string>

struct lua_State;

namespace lua0x {

	class state {
		lua_State* impl;
	public:

		// give an existing lua_State 
		state(lua_State* = 0);
		~state();
    
		operator lua_State*() const;

		void open();
		void close();

		// do string/file
		int string(const std::string& s) const;
		int file(const std::string& filename) const;
    
		// error string given return code of the above
		std::string error(int) const;

		// open libs
		void libs() const;

		// automatic open/close 
		struct raii_type {
			state& s;
			raii_type(state& s);
			~raii_type();
		};

		raii_type raii();

	};



}


#endif
