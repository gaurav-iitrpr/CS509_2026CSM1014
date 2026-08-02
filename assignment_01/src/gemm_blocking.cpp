#include "gemm_blocking.h"
#include <algorithm>

Matrix gemmBlocking(const Matrix& A,
                    const Matrix& B,
                    int M,
                    int K,
                    int N,
                    int blockSize)
{
    Matrix C(M, std::vector<int>(N, 0));

    for (int ii = 0; ii < M; ii += blockSize)
    {
        for (int jj = 0; jj < N; jj += blockSize)
        {
            for (int kk = 0; kk < K; kk += blockSize)
            {
                int iMax = std::min(ii + blockSize, M);
                int jMax = std::min(jj + blockSize, N);
                int kMax = std::min(kk + blockSize, K);

                for (int i = ii; i < iMax; i++)
                {
                    for (int j = jj; j < jMax; j++)
                    {
                        for (int k = kk; k < kMax; k++)
                        {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }

    return C;
}