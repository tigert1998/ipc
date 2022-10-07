#include <fcntl.h>
#include <glog/logging.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <string>

#include "message.h"

int main(int argc, char** argv) {
  auto key = ftok("ipc/message_queue", 0);

  auto id = msgget(key, 0);
  CHECK_GE(id, 0);

  for (int i = 1; i <= 100; i++) {
    Message msg;
    int32_t len = msgrcv(id, &msg, sizeof(msg.buf), i, IPC_NOWAIT);
    if (len < 0) {
      CHECK_EQ(errno, ENOMSG);
      LOG(WARNING) << "no message for type #" << i;
    } else {
      std::cout << std::string((char*)msg.buf) << std::endl;
    }
  }

  return 0;
}