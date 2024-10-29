#include <internal/syscall.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>

int nanosleep(const struct timespec *req, struct timespec *rem)
{
    int res = syscall(__NR_nanosleep, req, rem);

    if (res < 0) {
        return -1;
    }

    return 0;
}
