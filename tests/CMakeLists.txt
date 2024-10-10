# tests/CMakeLists.txt

# Include the src directory to access the server header files
include_directories(${CMAKE_SOURCE_DIR}/src)

# Define the source files for the test executable
set(TEST_SOURCES server_tests.cpp ${CMAKE_SOURCE_DIR}/src/hello_world_server.cpp)

# Create the test executable
add_executable(server_tests ${TEST_SOURCES})

# Link the test executable with httplib and Google Test
target_link_libraries(server_tests PRIVATE httplib::httplib gtest gtest_main)

# Add a test to be run by CTest
add_test(NAME ServerTests COMMAND server_tests)
