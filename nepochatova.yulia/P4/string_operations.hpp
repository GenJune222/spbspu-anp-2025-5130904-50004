#ifndef STRING_OPERATIONS_HPP
#define STRING_OPERATIONS_HPP
#include <iomanip>

namespace nepochatova
{
  char* readString(std::istream& in, size_t& length);
  int seq_sym(const char* str);
  size_t unc_sym(const char* str1, const char* str2, char* result, size_t result_capacity);
  size_t my_strlen(const char* str);
}
#endif