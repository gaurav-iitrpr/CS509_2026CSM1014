#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "../common/mst_csr.h"
#include <vector>

using namespace std;

struct MSTEdge
{
    int src;
    int dest;
    int weight;
};

vector<MSTEdge> kruskalMST(MSTCSR &csr, int vertices);

#endif