#include "mst_csr.h"
using namespace std;

void MSTCSR::buildCSR(Graph &graph)
{
    rowPtr.assign(graph.V + 1, 0);

    colIndex.clear();
    weights.clear();

    for (int i = 0; i < (int)graph.edges.size(); i++)
    {
        int u = graph.edges[i].src;
        int v = graph.edges[i].dest;

        rowPtr[u + 1]++;
        rowPtr[v + 1]++;
    }
for (int i = 1; i <= graph.V; i++)
    {
        rowPtr[i] += rowPtr[i - 1];
    }
int totalEntries = graph.edges.size() * 2;
 colIndex.resize(totalEntries);
    weights.resize(totalEntries);

    vector<int> temp = rowPtr;

    for (int i = 0; i < (int)graph.edges.size(); i++)
    {
        Edge edge = graph.edges[i];

        int pos1 = temp[edge.src];

        colIndex[pos1] = edge.dest;
        weights[pos1] = edge.weight;

        temp[edge.src]++;


        int pos2 = temp[edge.dest];

        colIndex[pos2] = edge.src;
        weights[pos2] = edge.weight;

        temp[edge.dest]++;
    }
}