#ifndef _JINJIAZHANG_PLAT_H_
#define _JINJIAZHANG_PLAT_H_

#ifdef linux
#else
using int64_t = long long;
#endif

// sleep for millisecond time
void app_sleep(int time);

// returns the millisecond since the 1970
int64_t app_time();

// fork in linux for daemon
void app_daemon();

#endif