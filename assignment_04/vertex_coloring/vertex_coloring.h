#ifndef VERTEX_COLORING_H
#define VERTEX_COLORING_H
#include "../../common/csr.h"
#include <vector>
std::vector<int> greedyVertexColoring(const CSR& csr);
bool validateColoring(const CSR& csr,const std::vector<int>& colors);
int countColors(const std::vector<int>& colors);
#endif
