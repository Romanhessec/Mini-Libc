#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <internal/syscall.h>
#include "../include/time.h"
unsigned int sleep(unsigned int seconds)
{
    struct timespec req = {seconds, 0};
    struct timespec rem = {0, 0};
    int ret;
 
    do {
        ret = nanosleep(&req, &rem);
        req = rem;
    } while (ret == -1 && errno == EINTR);

    return 0;
}