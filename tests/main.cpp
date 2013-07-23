#include<iostream>
#include<luabind/lua_include.hpp>
#include<luabind/luabind.hpp>
extern "C"{
#include<lualib.h>
};
int main(){
  lua_State* L;
  L = lua_open();
  luaL_openlibs(L);
  luaL_dostring(L, "print \"Mismatch\"");
  std::cout << "connetct to main " << std::endl;
};
