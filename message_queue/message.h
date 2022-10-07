#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <stdint.h>

struct Message {
  long type;
  int8_t buf[1 << 10];
};

#endif