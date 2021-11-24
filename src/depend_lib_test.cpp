#include "test_lib.h"
#include <glog/logging.h>
#include <gtest/gtest.h>

TEST(test_lib, test_lib) {
  auto result = testFunc("this is a test string");
  LOG(INFO) << "result " << result;
}
