#include <sys/types.h>
#include <unistd.h>

#include "gtestx/gtestx.h"

PERF_TEST(libc, getpid) {
  getpid();
}

