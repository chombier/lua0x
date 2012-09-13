#ifndef LUA_STATE_H
#define LUA_STATE_H

#include <string>

struct lua_State;

namespace lua {

  class state {
    lua_State* impl;
  public:

    state();
    ~state();
    
    operator lua_State*() const;

    // do string/file
    int string(const std::string& s) const;
    int file(const std::string& filename) const;
    
    // error string given return code of the above
    std::string error(int) const;

    // open libs
    void libs() const;

  };



}


#endif
