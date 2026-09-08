#ifndef PAGERANK_H
#define PAGERANK_H
#include "../../common/csr.h"
#include <vector>
struct PageRankResult{std::vector<double> ranks; int iterations; bool converged;};
PageRankResult pageRank(const CSR& csr,double damping,double tolerance,int maxIterations);
#endif
