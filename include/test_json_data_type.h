#pragma once

#include "nlohmann/json.hpp"
#include <iomanip>
#include <iostream>
#include <string>

namespace json_test {

// using nljson_t = nlohmann::ordered_json;
using nljson_t = nlohmann::json;

struct with_pod_array_t {
  std::string str;
  int arr[8]{0};
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(with_pod_array_t, str, arr);

struct complex_struct_t {
  with_pod_array_t pod_arr;
  int vi;
};

/* if implementation locate in cpp file and this is a so project,
 * the to_json/from_json functions must export to caller.
 */
void to_json(nljson_t &j, const complex_struct_t &c) {
  // clang-format off
  j = nljson_t{
    {"pod_arr", c.pod_arr},
    {"vi", c.vi}
  };
  // clang-format on
}

void from_json(const nljson_t &j, complex_struct_t &c) {
  j.at("pod_arr").get_to(c.pod_arr);
  j.at("vi").get_to(c.vi);
}

} // namespace json_test
