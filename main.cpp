
#include "module.h"
#include "state.h"

int main(int, char** ) {

  // lua state wrapper
  lua::state state;

  // init stuff and declare a global lua module 'cxx'
  lua::module::init( state, "cxx" );
  
  // declare a lua module under global name 'test'
  lua::module test("test");

  // binds a c++11 lambda as test.echo
  test("echo", [](const std::string& name) { 
      std::cout << name << std::endl; 
    });
  
  // register test module in lua
  state.string("cxx.load('test')");
  
  // calls test.echo
  state.string("test.echo('lolwat')");
  
  return 0;
}
