
#include <lua0x/module.h>
#include <lua0x/state.h>

int main(int, char** ) {

  // lua state wrapper
  lua0x::state state;

  // init stuff and declare the global lua module 'cxx'
  lua0x::module::init( state, "cxx" );
  
  // declare a lua module. it will appear under the lua global name
  // 'test' once loaded.
  lua0x::module test("test");
  
  // binds a lambda as test.echo
  test("echo", [](const std::string& name) { 
      std::cout << name << std::endl; 
    });
  
  // capturing lambdas
  int foo = 0;

  test
    ("get", [&] { return foo; } )
    ("set", [&](int x) { foo = x; } )
    ;
  
  // loads the test module in lua
  state.string("cxx.load('test')");
  
  // say hi from lua
  state.string("test.echo('hi thar !')");
  
  // modify foo from lua
  state.string("test.set( 42 )");
  
  // we need to open_libs before using tostring
  state.libs();

  // print foo value from lua
  state.string("test.echo( 'foo: ' .. test.get() )" );
  
  return 0;
}
