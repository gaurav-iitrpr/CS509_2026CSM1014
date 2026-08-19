#ifndef PRIMS_H
#define PRIMS_H
#include "../common/mst_csr.h"
#include <vector>
using namespace std;

vector<int> primMST(MSTCSR &csr, int vertices);

#endif