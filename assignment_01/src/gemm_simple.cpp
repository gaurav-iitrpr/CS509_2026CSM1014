#include "gemm_simple.h"

Matrix gemmSimple(const Matrix& A,
                  const Matrix& B,
                  int M,
                  int K,
                  int N)
{
    Matrix C(M, std::vector<int>(N, 0));

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < K; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}