#include "pagerank.h"
#include <cmath>
using namespace std;
PageRankResult pageRank(const CSR &csr, double damping, double tolerance, int maxIterations)
{
    int n = (int)csr.rowPtr.size() - 1;
    vector<double> rank(n, 1.0 / n), next(n);
    bool converged = false;
    int iterations = 0;
    for (int it = 1; it <= maxIterations; it++)
    {
        fill(next.begin(), next.end(), (1.0 - damping) / n);
        double dangling = 0;
        for (int u = 0; u < n; u++)
        {
            int out = csr.rowPtr[u + 1] - csr.rowPtr[u];
            if (out == 0)
                dangling += rank[u];
            else
            {
                double share = damping * rank[u] / out;
                for (int p = csr.rowPtr[u]; p < csr.rowPtr[u + 1]; p++)
                    next[csr.colIndex[p]] += share;
            }
        }
        double ds = damping * dangling / n;
        for (double &x : next)
            x += ds;
        double change = 0;
        for (int i = 0; i < n; i++)
            change += abs(next[i] - rank[i]);
        rank.swap(next);
        iterations = it;
        if (change <= tolerance)
        {
            converged = true;
            break;
        }
    }
    double sum = 0;
    for (double x : rank)
        sum += x;
    if (sum > 0)
        for (double &x : rank)
            x /= sum;
    return {rank, iterations, converged};
}
