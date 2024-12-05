cmake_minimum_required(VERSION 3.10)
project(GithubUserActivity)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories (for header files)
include_directories(include)

# Add all source files
set(SOURCES
    src/main.cpp
    src/GithubUserActivity.cpp
    src/HTTPClient.cpp
)

include_directories(include)
# Define the executable
add_executable(GithubUserActivity ${SOURCES})

# Find and link libcurl
find_package(CURL REQUIRED)
target_link_libraries(GithubUserActivity PRIVATE CURL::libcurl)