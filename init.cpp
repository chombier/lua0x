
#include <lua0x/module.h>

// called on package.loadlib('lua0x', 'init')
extern "C" int init(lua_State* L) {
  lua0x::module::init(L);
  return 0;
}

