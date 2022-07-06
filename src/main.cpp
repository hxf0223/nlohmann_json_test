#include <fstream>
#include <iostream>
#include <string>

#include "test_json_data_type.h"
#include <glog/logging.h>
#include <gtest/gtest.h>

TEST(json, save) {
  using namespace json_test;

  nljson_t js;
  complex_struct_t c;
  c.pod_arr_vec = std::vector<with_pod_array_t>(2);
  strcpy(c.name, "this is a test string.");
  to_json(js, c);

  std::ofstream file("test_data.json");
  file << js.dump(-1, ' ');
}

TEST(json, load) {
  using namespace json_test;

  std::ifstream file("test_data.json");
  if (file.is_open() == false) {
    std::cout << "load file fail" << std::endl;
    return;
  }

  nljson_t j = nljson_t::parse(file);
  CHECK(j.contains(std::string("pod_arr_vec"))) << "fail, not contain pod_arr_vec";
  auto js_pod_arr_vec = j["pod_arr_vec"][0];
  auto r = js_pod_arr_vec.find(std::string("str"));
  CHECK(r != js_pod_arr_vec.end());
  complex_struct_t c;

  from_json(j, c);

  nljson_t j2;
  to_json(j2, c);
  LOG(INFO) << j2;
}

TEST(json, loadfromstr) {
  std::string js_str = "{\"dso_file\": \"libdemo_rpc_module.so\", \"dso_args\": \"\"}";
  auto js2 = R"({"dso_file": "libdemo_rpc_module.so", "dso_args": ""})"_json;
  json_test::nljson_t js = json_test::nljson_t::parse(js_str);
  LOG(INFO) << js.dump();
  CHECK(js.find(std::string("dso_file")) != js.end()) << "No dso_file segment: " << js_str;
}

int main(int argc, char *argv[]) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_stderrthreshold = google::INFO;
  FLAGS_colorlogtostderr = true;

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
