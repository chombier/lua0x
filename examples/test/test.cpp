#include <lua0x/module.h>

// we wrap the module definition inside a singleton class ctor: the
// module will be automatically registered on library load
struct test {

  lua0x::module module;
  int foo;
  
  test() 
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

};

static test instance;

// dummy init 
extern "C" int init(lua_State*) {
  
  return 0;
}
