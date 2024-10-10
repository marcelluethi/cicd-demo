cmake_minimum_required(VERSION 3.10)

# Set the project name
project(SimpleWebServer)

# C++ Standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(FetchContent)

# Fetch cpp-httplib library
FetchContent_Declare(
  httplib
  GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
  GIT_TAG v0.10.3  # Specify the tag to ensure consistent versions
)

# Fetch Google Test library
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1  # Specify the desired version
)

# Download and make available the libraries
FetchContent_MakeAvailable(httplib googletest)

# Enable testing for the project
enable_testing()

# Add the source directory to the build
add_subdirectory(src)

# Add the tests directory to the build
add_subdirectory(tests)
