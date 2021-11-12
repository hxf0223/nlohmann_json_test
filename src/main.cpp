#include <fstream>
#include <iostream>
#include <string>

#include "test_json_data_type.h"
#include <glog/logging.h>
#include <gtest/gtest.h>

using namespace json_test;

TEST(json, save) {
  nljson_t js;
  complex_struct_t c;
  c.pod_arr_vec = std::vector<with_pod_array_t>(2);
  strcpy(c.name, "this is a test string.");
  to_json(js, c);

  std::ofstream file("test_data.json");
  file << js.dump(-1, ' ');
}

TEST(json, load) {
  std::ifstream file("test_data.json");
  if (file.is_open() == false) {
    std::cout << "load file fail" << std::endl;
    return;
  }

  nljson_t j = nljson_t::parse(file);
  complex_struct_t c;

  from_json(j, c);

  nljson_t j2;
  to_json(j2, c);
  LOG(INFO) << j2;
}

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_stderrthreshold = google::INFO;
  FLAGS_colorlogtostderr = true;

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
