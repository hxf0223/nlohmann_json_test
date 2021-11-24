# setup target for data dump library
set(test_lib_src
  test_lib.cc
)

add_library(test_lib SHARED ${test_lib_src})
target_link_libraries( test_lib ${TVM_RUNTIME_LIBS} pthread dl )

