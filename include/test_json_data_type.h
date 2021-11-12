#pragma once

#include "nlohmann/ordered_json.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

namespace json_test {

using nljson_t = nlohmann::ordered_json;
// using nljson_t = nlohmann::json;

struct with_pod_array_t {
  std::string str;
  int arr[8]{0};
};
NLOHMANN_DEFINE_ORDERED_TYPE_NON_INTRUSIVE(with_pod_array_t, str, arr);

struct complex_struct_t {
  std::vector<with_pod_array_t> pod_arr_vec;
  with_pod_array_t pod_arr;
  char name[32];
  int vi;
};

/* if implementation locate in cpp file and this is a so project,
 * the to_json/from_json functions must export to caller. */
void to_json(nljson_t &j, const complex_struct_t &c) {
  // clang-format off
  j = nljson_t{
    {"pod_arr_vec", c.pod_arr_vec},
    {"pod_arr", c.pod_arr},
    {"name", c.name},
    {"vi", c.vi}
  };
  // clang-format on
}

void from_json(const nljson_t &j, complex_struct_t &c) {
  j.at("pod_arr_vec").get_to(c.pod_arr_vec);
  j.at("pod_arr").get_to(c.pod_arr);
  j.at("vi").get_to(c.vi);

  std::string str;
  j.at("name").get_to(str);
  strcpy(c.name, str.c_str());
}

} // namespace json_test
