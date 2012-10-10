#include <lua0x/module.h>

// we wrap the module definition inside a singleton class ctor: the
// module will be automatically registered on library load
static struct def {

  lua0x::module module;
  int foo;
  
	def() 
    : module("test"),
      foo(0) {

    module
    ("echo", [](const std::string& name) { 
      std::cout << name << std::endl; 
    })
    ("get", [&] { return foo; } )
    ("set", [&](int x) { foo = x; } )
    ;
  }

} instance;


extern "C" int luaopen_test(lua_State* L) {
	instance.module.load( L );
	
  return 0;
}
