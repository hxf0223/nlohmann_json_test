#include <fstream>
#include <iostream>
#include <string>

#include <glog/logging.h>
#include <gtest/gtest.h>

#include "test_vector_of_ptr_type.h"

TEST(vector_of_ptr, toJson) {
  using namespace test_vector_of_ptr;

  int v = 1;
  nljson_t j;
  ptr_of_pod_arr_t ptr_of_arr;
  ptr_of_arr.array = std::vector<pod_t *>(3);
  for (auto &p : ptr_of_arr.array) {
    p = new pod_t(v++);
  }

  to_json(j, ptr_of_arr);
  LOG(INFO) << j.dump();
}