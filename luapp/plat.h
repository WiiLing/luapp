#ifndef _JINJIAZHANG_PLAT_H_
#define _JINJIAZHANG_PLAT_H_

#include "lualib/lualib.h"
#include "protolog/protolog.h"

#ifdef linux
#else
using int64_t = long long;
using uint64_t = unsigned long long;
#endif

#ifdef _JINJIAZHANG_PROTOLOG_H_
#define luapp_trace(fmt, ...)  proto_trace(fmt, __VA_ARGS__)
#define luapp_debug(fmt, ...)  proto_debug(fmt, __VA_ARGS__)
#define luapp_info(fmt, ...)   proto_info(fmt, __VA_ARGS__)
#define luapp_warn(fmt, ...)   proto_warn(fmt, __VA_ARGS__)
#define luapp_error(fmt, ...)  proto_error(fmt, __VA_ARGS__)
#define luapp_fatal(fmt, ...)  proto_fatal(fmt, __VA_ARGS__)
#else
#define luapp_trace(fmt, ...)
#define luapp_debug(fmt, ...)
#define luapp_info(fmt, ...)
#define luapp_warn(fmt, ...)
#define luapp_error(fmt, ...)
#define luapp_fatal(fmt, ...)
#endif

// sleep for millisecond time
void sys_sleep(int time);

// returns the millisecond since the 1970
int64_t sys_mstime();

// returns the time when the file last modify
int64_t sys_filetime(const char* file);

// returns the md5hex of the file
std::string sys_md5file(const char* file);

// concat string from lua stack
std::string lua_stackview(lua_State* L);

// fork in linux for daemon
void app_daemon();

int luaopen_system(lua_State* L);

int luaopen_protolog(lua_State* L);

#endif