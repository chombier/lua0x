#include <lua0x/module.h>
#include <lua0x/state.h>

#include <iostream>
#include <readline/readline.h>

static struct def {
	
	lua0x::module module;

	std::string prompt;
	
	def() 
		: module("readline"),
		  prompt("> ")
	{
		
		module
			("get", [&] {
				const char* line = ::readline(prompt.c_str());
				
				return std::string( line );
			})
			("init", [&] {
				std::cout << "readline init lol" << std::endl;
				
			})
			("prompt", [&](const std::string& p) {
				prompt = p;
			});
		

	}
	
	
} instance;

extern "C" int luaopen_readline(lua_State* L) {
	instance.module.load(L);
  return 0;
}
