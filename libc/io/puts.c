#include <stdio.h>
#include <internal/io.h>
#include <internal/syscall.h>
#include <internal/types.h>

int puts(const char* msg) {
    int count = 1;
    for (; *msg != '\0'; msg++, count++){
        write(1, msg, 1);
    }
    write(1, "\n", 1);
    return count;
}