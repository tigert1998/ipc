add_executable(pipe_server "pipe/server.cc")
add_executable(pipe_client "pipe/client.cc")
target_link_libraries(
    pipe_server
    glog
)
target_link_libraries(
    pipe_client
    glog
)