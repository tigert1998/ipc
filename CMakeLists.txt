project(ipc)

add_subdirectory(third_party/glog)

include("pipe/pipe.cmake")
include("message_queue/message_queue.cmake")
