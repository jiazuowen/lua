#include <stdio.h>
#include <stdlib.h>

#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

#define jacloglib_c
#define LUA_LIB

static int log(lua_State* L) 
{
    int num = luaL_checkinteger(L, 1);
    printf("log num :%d\n", num);
    return 0;
}

static int logEx(lua_State* L)
{
    size_t len = 0;
    const char* str = luaL_checklstring(L, 1, &len);
    printf("logEx %s %d\n", str, len);
    return 0;
}

static const luaL_Reg jacloglib[] = {
    {"log", log},
    {"logEx", logEx},
    {NULL, NULL}
};

/**
 * Log Lib 
 */
int luaopen_jaclog(lua_State* L) 
{
    luaL_register(L, LUA_JAC_LOGLIBNAME, jacloglib);
    return 1;
}