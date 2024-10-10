# Add executable for the main application
add_executable(hello_world_server main.cpp hello_world_server.cpp)
target_link_libraries(hello_world_server PRIVATE httplib::httplib)
