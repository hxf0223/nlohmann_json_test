cmake_minimum_required(VERSION 3.2)
project(json_test C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set( CMAKE_C_FLAGS "-O0 -g -Wall -rdynamic -std=c++11 -fPIC ${CMAKE_C_FLAGS}" )
set( CMAKE_CXX_FLAGS "-O0 -g -Wall -rdynamic -std=c++11 -fPIC ${CMAKE_CXX_FLAGS}" )

set(GTEST_ROOT "/usr/local" CACHE STRING "set google test and glog's top dir.")
message(STATUS "google-test's top dir: ${GTEST_ROOT}")

# cmake -DGLOG_ROOT_DIR=???
# set( CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )
# find_package(Glog REQUIRED)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
SET(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${GTEST_ROOT}/include")
link_directories("${GTEST_ROOT}/lib")

add_subdirectory("src")

