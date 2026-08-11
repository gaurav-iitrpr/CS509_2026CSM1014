#include "csr.h"
using namespace std;

void CSR::buildCSR(Graph &graph)
{
    rowPtr.assign(graph.V + 1, 0);
colIndex.clear();
weights.clear();

    for (int i = 0; i < graph.E; i++){
        rowPtr[graph.edges[i].src + 1]++;
    }
for (int i = 1; i <= graph.V; i++){
        rowPtr[i] += rowPtr[i - 1];
    }
colIndex.resize(graph.E);
weights.resize(graph.E);

    vector<int> temp = rowPtr;

    for (int i = 0; i < graph.E; i++){
        Edge e = graph.edges[i];
int pos = temp[e.src];
colIndex[pos] = e.dest;
weights[pos] = e.weight;
temp[e.src]++;
    }
}