#ifndef TIME_H
#define TIME_H    1

#ifdef cplusplus
extern "C" {
#endif

#include <internal/types.h>

struct timespec
{
    uint64_t sec;
    uint64_t nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
unsigned int sleep(unsigned int seconds);

#ifdef cplusplus
}
#endif

#endif