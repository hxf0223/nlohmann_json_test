#pragma once

#include "nlohmann/ordered_json.hpp"
#include <iomanip> // std::setw
#include <iostream>
#include <string>
#include <vector>

namespace test_vector_of_ptr {
using nljson_t = nlohmann::ordered_json;

struct pod_t {
  pod_t() = default;
  pod_t(int v) : value(v) {
  }
  int value;
};
NLOHMANN_DEFINE_ORDERED_TYPE_NON_INTRUSIVE(pod_t, value);

inline void to_json(nljson_t &j, const std::vector<pod_t *> &array) { // match type of std::vector<pod_t*>
  nljson_t arr_j;
  for (auto ptr : array) {
    arr_j.push_back(*ptr);
  }
  j = arr_j;
}

struct ptr_of_pod_arr_t {
  std::vector<pod_t *> array;
};

inline void to_json(nljson_t &j, const ptr_of_pod_arr_t &ptrOfArray) {
  j = {{"array", ptrOfArray.array}};
}

} // namespace test_vector_of_ptr