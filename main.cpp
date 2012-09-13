
#include <lua0x/module.h>
#include <lua0x/state.h>

int main(int, char** ) {

  // lua state wrapper
  lua0x::state state;

  // init stuff and declare a global lua module 'cxx'
  lua0x::module::init( state, "cxx" );
  
  // declare a lua module: it will go under global name 'test' once
  // loaded.
  lua0x::module test("test");
  
  // binds a c++11 lambda as test.echo
  test("echo", [](const std::string& name) { 
      std::cout << name << std::endl; 
    });
  
  // loads the test module in lua
  state.string("cxx.load('test')");
  
  // calls test.echo
  state.string("test.echo('lolwat')");
  
  return 0;
}
