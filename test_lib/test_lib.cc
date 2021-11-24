#include "test_lib.h"
#include <iostream>

DATA_DUMP_FUNC_VISIBILITY int testFunc(std::string str) {
  std::cout << "str = " << str << std::endl;
  return 1;
}
