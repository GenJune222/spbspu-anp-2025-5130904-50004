#include <cstdlib>
#include "string_operations.hpp"

char* nepochatova::readString(std::istream& in, size_t& length)
{
  std::ios::fmtflags saved = in.flags();
  in >> std::noskipws;

  size_t bufSize = 32;
  length = 0;

  char* str = static_cast<char*>(malloc(bufSize));
  if (!str)
  {
    in.flags(saved);
    return nullptr;
  }

  while (true)
  {
    char c;
    if (!(in >> c) || c == '\n')
    {
      break;
    }

    if (length + 1 == bufSize)
    {
      bufSize *= 2;
      char* resized = static_cast<char*>(realloc(str, bufSize));
      if (!resized)
      {
        free(str);
        in.flags(saved);
        return nullptr;
      }
      str = resized;
    }

    str[length++] = c;
  }

  str[length] = '\0';
  in.flags(saved);
  return str;
}

size_t nepochatova::my_strlen(const char* str)
{
  size_t len = 0;
  if (!str) return 0;
  while (str[len] != '\0') {
    len++;
  }
  return len;
}

int nepochatova::seq_sym(const char* str)
{
  if (str == nullptr){
    return 0;
  }
  int count = 0;
  for (size_t i = 1; str[i] != '\0'; i++){
    if (str[i] == str[i - 1]){
      count++;
    }
  }
  return count;
}

size_t nepochatova::unc_sym(const char* str1, const char* str2, char* result, size_t result_capacity)
{
  if (str1 == 0 || str2 == 0 || result == 0 || result_capacity == 0){
    return 0;
  }

  size_t index = 0;


  for (size_t i = 0; str1[i] != '\0' && index < result_capacity - 1; i++){
    int found_in_str2 = 0;
    for (size_t j = 0; str2[j] != '\0'; j++){
      if (str1[i] == str2[j]){
        found_in_str2 = 1;
        break;
      }
    }

    if (!found_in_str2){
      int already_added = 0;
      for (size_t k = 0; k < index; k++){
        if (result[k] == str1[i]){
          already_added = 1;
          break;
        }
      }

      if (!already_added){
        result[index++] = str1[i];
      }
    }
  }

  for (size_t i = 0; str2[i] != '\0' && index < result_capacity - 1; i++){
    int found_in_str1 = 0;
    for (size_t j = 0; str1[j] != '\0'; j++){
      if (str2[i] == str1[j]){
        found_in_str1 = 1;
        break;
      }
    }

    if (!found_in_str1){
      int already_added = 0;
      for (size_t k = 0; k < index; k++){
        if (result[k] == str2[i]){
          already_added = 1;
          break;
        }
      }
      if (!already_added){
        result[index++] = str2[i];
      }
    }
  }

  if (index < result_capacity){
    result[index] = '\0';
  }
  else if (result_capacity > 0)
  {
    result[result_capacity - 1] = '\0';
  }
  return index;
}