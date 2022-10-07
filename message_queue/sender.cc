#include <fcntl.h>
#include <glog/logging.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

#include <string>

#include "message.h"

int main(int argc, char** argv) {
  auto key = ftok("ipc/message_queue", 0);

  auto id = msgget(key, IPC_CREAT | IPC_EXCL | 0666);
  if (id < 0 && errno == EEXIST) {
    id = msgget(key, 0);
    CHECK_GE(id, 0);
  }

  for (int i = 1; i <= 100; i++) {
    std::string text =
        std::string("Hello, this is message #") + std::to_string(i) + ".";
    Message msg;
    msg.type = i;
    std::copy(text.begin(), text.end(), msg.buf);
    msg.buf[text.size()] = 0;

    CHECK_EQ(msgsnd(id, &msg, sizeof(msg.buf), 0), 0);
  }

  return 0;
}