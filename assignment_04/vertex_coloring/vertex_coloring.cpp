#include "vertex_coloring.h"
#include <algorithm>
#include <numeric>
using namespace std;
vector<int> greedyVertexColoring(const CSR &csr)
{
    int n = (int)csr.rowPtr.size() - 1;
    vector<int> order(n), degree(n);
    iota(order.begin(), order.end(), 0);
    for (int v = 0; v < n; v++)
        degree[v] = csr.rowPtr[v + 1] - csr.rowPtr[v];
    sort(order.begin(), order.end(), [&](int a, int b)
         {if(degree[a]!=degree[b]) return degree[a]>degree[b]; return a<b; });
    vector<int> color(n, -1), used(n + 1, 0);
    int stamp = 0;
    for (int v : order)
    {
        ++stamp;
        for (int p = csr.rowPtr[v]; p < csr.rowPtr[v + 1]; p++)
        {
            int u = csr.colIndex[p];
            if (color[u] >= 0)
                used[color[u]] = stamp;
        }
        int c = 0;
        while (c <= n && used[c] == stamp)
            ++c;
        color[v] = c;
    }
    return color;
}
bool validateColoring(const CSR &csr, const vector<int> &colors)
{
    int n = (int)csr.rowPtr.size() - 1;
    if ((int)colors.size() != n)
        return false;
    for (int v = 0; v < n; v++)
        for (int p = csr.rowPtr[v]; p < csr.rowPtr[v + 1]; p++)
        {
            int u = csr.colIndex[p];
            if (u < 0 || u >= n || colors[u] == colors[v])
                return false;
        }
    return true;
}
int countColors(const vector<int> &colors)
{
    int m = -1;
    for (int c : colors)
        m = max(m, c);
    return m + 1;
}
