#ifndef GEMM_BLOCKING_H
#define GEMM_BLOCKING_H
#include "matrix.h"

Matrix gemmBlocking(const Matrix& A,
                    const Matrix& B,
                    int M,
                    int K,
                    int N,
                    int blockSize);

#endif