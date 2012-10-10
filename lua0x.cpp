#include <lua0x/module.h>

extern "C" {
	int luaopen_lua0x (lua_State *L);
}

int luaopen_lua0x (lua_State *L) {
	return lua0x::module::init( L );
}
