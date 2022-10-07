#include <fcntl.h>
#include <glog/logging.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>

int main() {
  auto fd = open("fifo", O_RDONLY);
  CHECK_GE(fd, 0);
  char buf[1 << 10];
  int size = read(fd, buf, sizeof(buf));
  close(fd);

  std::cout << std::string(buf, buf + size) << std::endl;

  return 0;
}