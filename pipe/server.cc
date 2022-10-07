#include <fcntl.h>
#include <glog/logging.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  CHECK_EQ(mkfifo("fifo", S_IFIFO | 0666), 0);
  auto fd = open("fifo", O_WRONLY);
  CHECK_GE(fd, 0);
  std::string msg = "Hello, World!";
  write(fd, msg.c_str(), msg.size());
  close(fd);

  return 0;
}