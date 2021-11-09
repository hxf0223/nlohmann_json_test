#pragma once

#include "nlohmann/json.hpp"
#include <string>

namespace json_test {

using nljson_t = nlohmann::ordered_json;

struct with_pod_array_t {
  std::string str;
  int arr[8]{0};
};

void to_json(nljson_t &j, const with_pod_array_t &desc) {
  j = nljson_t{{"str", desc.str}, {"arr", desc.arr}};
}

void from_json(const nljson_t &j, with_pod_array_t &desc) {
  j.at("str").get_to(desc.str);
  j.at("arr").get_to(desc.arr);
}

struct complex_struct_t {
  with_pod_array_t pod_arr;
  int vi;
};

/* if implementation locate in cpp file and this is a so project,
 * the to_json/from_json functions must export to caller.
 */
void to_json(nljson_t &j, const complex_struct_t &c) {
  j = nljson_t{{"pod_arr", c.pod_arr}, {"vi", c.vi}};
}

void from_json(const nljson_t &j, complex_struct_t &c) {
  j.at("pod_arr").get_to(c.pod_arr);
  j.at("vi").get_to(c.vi);
}

} // namespace json_test
