#ifndef MST_CSR_H
#define MST_CSR_H

#include "mst_graph.h"
#include <vector>

using namespace std;

class MSTCSR
{
public:

    vector<int> rowPtr;
    vector<int> colIndex;
    vector<int> weights;

    void buildCSR(Graph &graph);
};

#endif