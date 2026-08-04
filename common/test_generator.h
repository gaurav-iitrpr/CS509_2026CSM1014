#ifndef TEST_GENERATOR_H
#define TEST_GENERATOR_H

#include <string>

void generateTestFile(const std::string& filename,
                      int M, int K, int N,
                      int minValue = 1,
                      int maxValue = 10);

#endif