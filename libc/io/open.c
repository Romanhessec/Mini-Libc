// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/stat.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	int mode = 0;
    if (flags & O_CREAT) {
        va_list arg;
        va_start(arg, flags);
        mode = va_arg(arg, int);
        va_end(arg);
    }

    int ret = syscall(2, filename, flags, mode);
    if (ret < 0) {
        errno = -ret;
        return -1;
    }
    return ret;
}
