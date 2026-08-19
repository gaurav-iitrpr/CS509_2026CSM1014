#include "prims.h"
#include <climits>

using namespace std;

vector<int> primMST(MSTCSR &csr, int vertices)
{
    vector<int> key(vertices, INT_MAX);
    vector<int> parent(vertices, -1);
    vector<bool> inMST(vertices, false);

    key[0] = 0;
    for (int count = 0; count < vertices; count++)
    {
        int u = -1;
        int minKey = INT_MAX;

        for (int i = 0; i < vertices; i++)
        {
            if (!inMST[i] && key[i] < minKey)
            {
                minKey = key[i];
                u = i;
            }
        }

        if (u == -1)
            break;


        inMST[u] = true;

        for (int i = csr.rowPtr[u];
             i < csr.rowPtr[u + 1];
             i++)
        {
            int v = csr.colIndex[i];
            int weight = csr.weights[i];


            if (!inMST[v] && weight < key[v])
            {
                key[v] = weight;
                parent[v] = u;
            }
        }
    }


    return parent;
}