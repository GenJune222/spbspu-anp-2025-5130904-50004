#include <iostream>
#include "string_operations.hpp"

int main()
{
  size_t len1 = 0;
  char *data1 = nepochatova::readString(std::cin, len1);

  const char *data2 = "test string";
  size_t len2 = 0;

  while (data2[len2] != '\0') {
    len2++;
  }

  if (!data1) {
    std::cerr << "Memory error or EOF" << "\n";
    return 1;
  }

  if (len1 == 0) {
    std::cerr << "Empty input" << "\n";
    free(data1);
    return 1;
  }

  int seq_count1 = nepochatova::seq_sym(data1);
  int seq_count2 = nepochatova::seq_sym(data2);

  std::cout << "First string has " << seq_count1 << " sequential symbol pairs\n";
  std::cout << "Second string has " << seq_count2 << " sequential symbol pairs\n";

  size_t max_result_size = len1 + len2 + 1;
  char *result_buffer = (char *) malloc(max_result_size);

  if (!result_buffer) {
    std::cerr << "Memory error for result buffer" << "\n";
    free(data1);
    return 1;
  }

  size_t unc_len = nepochatova::unc_sym(data1, data2, result_buffer, max_result_size);

  if (unc_len > 0) {
    std::cout << "Unique symbols :" << result_buffer << "\n";
  } else {
    std::cout << "No unique symbols found" << "\n";
  }

  free(data1);
  free(result_buffer);

  return 0;
}