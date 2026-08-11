#ifndef CSR_H
#define CSR_H
#include "graph.h"
#include <vector>

using namespace std;

class CSR{
public:

    vector<int> rowPtr;
    vector<int> colIndex;
    vector<int> weights;

    void buildCSR(Graph &graph);
};

#endif