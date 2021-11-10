#ifndef INCLUDE_NLOHMANN_ORDERED_JSON_H_
#define INCLUDE_NLOHMANN_ORDERED_JSON_H_

#include "json.hpp"

#define NLOHMANN_DEFINE_ORDERED_TYPE_NON_INTRUSIVE(Type, ...)                                                          \
  inline void to_json(nlohmann::ordered_json &nlohmann_json_j, const Type &nlohmann_json_t) {                          \
    NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_TO, __VA_ARGS__))                                           \
  }                                                                                                                    \
  inline void from_json(const nlohmann::ordered_json &nlohmann_json_j, Type &nlohmann_json_t) {                        \
    NLOHMANN_JSON_EXPAND(NLOHMANN_JSON_PASTE(NLOHMANN_JSON_FROM, __VA_ARGS__))                                         \
  }

#endif
