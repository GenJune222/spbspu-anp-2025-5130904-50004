#include <fstream>
#include <stdexcept>
#include <iostream>
#include "io.h"

int main(int argc, char ** argv)
{
  int num = 0;

  try {
    nepochatova::checkArgs(argc, argv);
    num = argv[1][0] - '0';
  } catch (const std::exception & e) {
    std::cerr << e.what() << "\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t n = 0, m = 0;
  input >> n >> m;
  if (input.fail()) {
    std::cerr << "Matrix unread" << "\n";
    return 2;
  }
  int * arr = nullptr;
  const size_t MaxStaticArraySize= 1000;
  int staticMatrix[MaxStaticArraySize];

  if (num == 1) {
    if (n * m > MaxStaticArraySize) {
      std::cerr << "Matrix too large for static mode\n";
      return 2;
    }
    arr = staticMatrix;
  } else {
    arr = new int[n * m];
  }

  try {
    nepochatova::readMatrix(input, arr, n, m);
    std::ofstream output(argv[3]);
    if (!output.is_open()) {
      throw std::runtime_error("Cannot open output file");
    }
    nepochatova::transformMatrixSpiral(arr, n, m);
    nepochatova::transformMatrixCircular(arr, n, m);
    nepochatova::writeMatrix(output, arr, n, m);
    if (num == 2) {
      delete[] arr;
    }
  } catch (const std::exception & e) {
    std::cerr << e.what() << "\n";
    if (num == 2) {
      delete[] arr;
    }
    return 2;
  }

  return 0;
}
