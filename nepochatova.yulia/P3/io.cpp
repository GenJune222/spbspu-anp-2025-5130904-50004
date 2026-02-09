#include <stdexcept>
#include "io.h"

int nepochatova::checkArgs(int argc, char **argv)
{
  if (argc < 4) {
    throw std::invalid_argument("Not enough arguments");
  }
  if (argc > 4) {
    throw std::invalid_argument("Too many arguments");
  }

  const char *p = argv[1];
  if (*p != '1' && *p != '2') {
    throw std::invalid_argument("First parameter is out of range");
  }

  if (*p == '\0') {
    throw std::invalid_argument("First parameter is not a number");
  }
  while (*p) {
    if (*p < '0' || *p > '9') {
      throw std::invalid_argument("First parameter is not a number");
    }
    ++p;
  }
  return 0;
}

void nepochatova::readMatrix(std::istream& in, int* arr, size_t n, size_t m)
{
  if (n == 0 || m == 0) {
    return;
  }

  for (size_t i = 0; i < n * m; ++i) {
    if (!(in >> arr[i])) {
      throw std::runtime_error("Invalid matrix data");
    }
  }
}

void nepochatova::writeMatrix(std::ofstream &out, const int *arr, size_t n, size_t m)
{
  if (arr == nullptr || n == 0 || m == 0) {
    out << "0 0\n";
    return;
  }

  for (size_t i = 0; i < n; ++i) {
    for (size_t j = 0; j < m; ++j) {
      out << arr[i * m + j];
      if (j != m - 1) out << " ";
    }
    out << "\n";
  }
}
