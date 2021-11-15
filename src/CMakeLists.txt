# setup target for data dump library
set(json_test_src
  test_vector_of_ptr_type.cpp
  test_optional_type.cpp
  main.cpp
)

add_executable(json_test ${json_test_src})
target_link_libraries(json_test pthread dl gtest glog)

