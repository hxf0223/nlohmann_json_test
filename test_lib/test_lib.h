#ifndef _H_TEST_LIB_
#define _H_TEST_LIB_

#include <string>

#ifdef __cplusplus
extern "C" {
#endif

#if defined(_MSC_VER)
#define DATA_DUMP_FUNC_VISIBILITY _declspec(dllexport)
#else
#define DATA_DUMP_FUNC_VISIBILITY __attribute__((visibility("default")))
#endif

DATA_DUMP_FUNC_VISIBILITY int testFunc(std::string str);

#ifdef __cplusplus
}
#endif

#endif