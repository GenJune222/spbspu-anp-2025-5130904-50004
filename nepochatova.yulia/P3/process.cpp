#include "io.h"

void nepochatova::transformMatrixSpiral(int *arr, size_t n, size_t m)
{
  if (n == 0 || m == 0 || arr == nullptr)
    return;

  size_t top = 0;
  size_t bottom = n - 1;
  size_t left = 0;
  size_t right = m - 1;
  size_t increment = 1;

  while (top <= bottom && left <= right) {
    for (size_t j = left; j <= right; j++) {
      arr[bottom * m + j] += increment;
      increment++;
    }
    if (bottom == 0) {
      break;
    }
    bottom--;

    for (size_t i = bottom; i >= top; i--) {
      arr[i * m + right] += increment;
      increment++;
      if (i == 0) {
        break;
      }
    }
    if (right == 0) {
      break;
    }
    right--;

    if (top <= bottom) {
      for (size_t j = right; j >= left; j--) {
        arr[top * m + j] += increment;
        increment++;
        if (j == 0) {
          break;
        }
      }
      top++;
    }

    if (left <= right) {
      for (size_t i = top; i <= bottom; i++) {
        arr[i * m + left] += increment;
        increment++;
      }
      left++;
    }
  }
}

void nepochatova::transformMatrixCircular(int *arr, size_t n, size_t m)
{
  if (arr == nullptr || n == 0 || m == 0) return;

  size_t layers = (n < m ? n : m);
  layers = (layers + 1) / 2;

  for (size_t layer = 0; layer < layers; ++layer) {
    size_t inc = layer + 1;

    size_t top = layer;
    size_t bottom = n - layer - 1;
    size_t left = layer;
    size_t right = m - layer - 1;

    if (top > bottom || left > right) break;

    for (size_t col = left; col <= right; ++col) {
      arr[top * m + col] += inc;
    }

    if (bottom > top) {
      for (size_t col = left; col <= right; ++col) {
        arr[bottom * m + col] += inc;
      }
    }

    if (right > left) {
      for (size_t row = top + 1; row < bottom; ++row) {
        arr[row * m + left] += inc;
      }
    }

    if (right > left && bottom > top) {
      for (size_t row = top + 1; row < bottom; ++row) {
        arr[row * m + right] += inc;
      }
    }
  }
}

