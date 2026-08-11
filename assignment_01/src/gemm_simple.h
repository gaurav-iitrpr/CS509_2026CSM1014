#ifndef GEMM_SIMPLE_H
#define GEMM_SIMPLE_H

#include "matrix.h"

Matrix gemmSimple(const Matrix& A,
                  const Matrix& B,
                  int M,
                  int K,
                  int N);

#endif