#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>
#include "../include/time.h"

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret;

    do {
        ret = syscall(35, req, rem);
    } while (ret == -1 && errno == EINTR);

    return ret;
}