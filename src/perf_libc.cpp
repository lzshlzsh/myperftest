#include <sys/types.h>
#include <sys/socket.h>
#include <sys/shm.h>
#include <unistd.h>

#include "gtestx/gtestx.h"

namespace {

/**
 * @brief 
 * @class SysVShmTest
 */
class SysVShmTest: public ::testing::Test
{
protected:
  virtual void SetUp() override {
    shm_id_ = shmget(SHM_KEY_, 4096, IPC_CREAT | 0644);
    ASSERT_NE(shm_id_, -1);
  }

  virtual void TearDown() override {
    ASSERT_NE(shmctl(shm_id_, IPC_RMID, NULL), -1);
  }

  int shm_id_;
  static constexpr key_t SHM_KEY_ = 0x10034;
};

}

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

PERF_TEST_F(SysVShmTest, shmat_dt) {
  void *addr = shmat(this->shm_id_, NULL, SHM_RDONLY);
  ASSERT_TRUE(addr != reinterpret_cast<void *>(-1)) << PERF_ABORT;
  ASSERT_EQ(shmdt(addr), 0) << PERF_ABORT;
}

PERF_TEST_F(SysVShmTest, shmat) {
  shmat(this->shm_id_, NULL, SHM_RDONLY);
}

PERF_TEST_F(SysVShmTest, shmdt) {
  shmdt(NULL);
}

PERF_TEST_F(SysVShmTest, shmget) {
  auto shm_id = shmget(SHM_KEY_, 4096, IPC_CREAT | 0644);
  ASSERT_NE(shm_id, -1) << PERF_ABORT;
}

PERF_TEST_F(SysVShmTest, shmctl) {
  struct shmid_ds shm_info;
  ASSERT_NE(shmctl(shm_id_, IPC_STAT, &shm_info), -1) << PERF_ABORT;
}
