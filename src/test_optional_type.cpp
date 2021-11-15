#include <fstream>
#include <iostream>
#include <string>

#include <glog/logging.h>
#include <gtest/gtest.h>

#include "test_optional_type.h"

TEST(optional, json) {
  using namespace test_optional;

  nljson_t j;
  optional_t opt;
  opt.str1 = "a string";
  to_json(j, opt);
  LOG(INFO) << j.dump();

  optional_t opt2;
  from_json(j, opt2);
  ASSERT_TRUE(opt2.opt_str == opt.opt_str);
  ASSERT_TRUE(opt2.str1 == opt.str1);

  opt.opt_str = "opt string.";
  opt.str1 = "another string.";
  to_json(j, opt);
  LOG(INFO) << j.dump();
}