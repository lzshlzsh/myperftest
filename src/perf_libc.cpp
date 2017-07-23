#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include "gtestx/gtestx.h"

PERF_TEST(libc, getpid) {
  getpid();
}

PERF_TEST(libc, socket_close) {
  int fd = socket(AF_INET, SOCK_STREAM, 0);
  ASSERT_GE(fd, 0);
  ASSERT_EQ(close(fd), 0);
}

PERF_TEST(libc, socket) {
  socket(AF_INET, SOCK_STREAM, 0);
}

PERF_TEST(libc, close) {
  close(-1);
}
