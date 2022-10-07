add_executable(message_queue_sender "message_queue/sender.cc")
add_executable(message_queue_receiver "message_queue/receiver.cc")

target_link_libraries(
    message_queue_sender
    glog
)
target_link_libraries(
    message_queue_receiver
    glog
)
