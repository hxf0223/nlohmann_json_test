cmake_minimum_required(VERSION 3.2)
project(json_test C CXX)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set( CMAKE_C_FLAGS "-O0 -g -Wall -rdynamic -std=c++14 -fPIC ${CMAKE_C_FLAGS}" )
set( CMAKE_CXX_FLAGS "-O0 -g -Wall -rdynamic -std=c++14 -fPIC ${CMAKE_CXX_FLAGS}" )

set(GTEST_ROOT "/usr/local" CACHE STRING "set google test and glog's top dir.")
message(STATUS "google-test's top dir: ${GTEST_ROOT}")

# cmake -DGLOG_ROOT_DIR=???
# set( CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )
# find_package(Glog REQUIRED)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/bin)
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
SET(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")

include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories(SYSTEM "${GTEST_ROOT}/include")
link_directories("${GTEST_ROOT}/lib")

include_directories("${PROJECT_SOURCE_DIR}/test_lib")
link_directories("${PROJECT_SOURCE_DIR}/lib")

add_subdirectory("src") # target name json_test
add_subdirectory("test_lib") # target name test_lib
add_dependencies(json_test test_lib)
