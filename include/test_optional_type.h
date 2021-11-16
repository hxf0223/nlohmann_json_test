#pragma once

#include "nlohmann/ordered_json.hpp"
#include <boost/optional.hpp>
#include <iomanip> // std::setw
#include <iostream>
#include <memory> // std::unique_ptr
#include <string>
#include <vector>

namespace nlohmann {
using nljson_t = nlohmann::json;

// partial specialization (full specialization works too)
template <typename T>
struct adl_serializer<boost::optional<T>> {
  static void to_json(nljson_t &j, const boost::optional<T> &opt) {
    if (opt == boost::none) {
      j = nullptr;
    } else {
      j = *opt; // this will call adl_serializer<T>::to_json which will
                // find the free function to_json in T's namespace!
    }
  }

  static void from_json(const nljson_t &j, boost::optional<T> &opt) {
    if (j.is_null()) {
      opt = boost::none;
    } else {
      opt = j.get<T>(); // same as above, but with
                        // adl_serializer<T>::from_json
    }
  }
};

} // namespace nlohmann

namespace test_optional {
using nljson_t = nlohmann::json;

struct pod_t {
  std::string str;
};
NLOHMANN_DEFINE_ORDERED_TYPE_NON_INTRUSIVE(pod_t, str);

struct optional_t {
  boost::optional<std::string> opt_str;
  std::string str1;
};

inline void to_json(nljson_t &j, const optional_t &opt) {
  j = {{"opt_str", opt.opt_str}, {"str1", opt.str1}};
}

inline void from_json(const nljson_t &j, optional_t &opt) {
  j["opt_str"].get_to(opt.opt_str);
  j["str1"].get_to(opt.str1);
}

// NLOHMANN_DEFINE_ORDERED_TYPE_NON_INTRUSIVE(optional_t, opt_str, str1);

} // namespace test_optional