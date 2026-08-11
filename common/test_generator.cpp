#include "test_generator.h"

#include <fstream>
#include <random>
#include <ctime>

using namespace std;

void generateTestFile(const string& filename,
                      int M, int K, int N,
                      int minValue,
                      int maxValue)
{
    ofstream fout(filename);

    if (!fout)
    {
        return;
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(minValue, maxValue);

    fout << M << " " << K << " " << N << "\n";

    // matrix A
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            fout << dist(gen) << " ";
        }
        fout << "\n";
    }

    // matrix B
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            fout << dist(gen) << " ";
        }
        fout << "\n";
    }

    fout.close();
}