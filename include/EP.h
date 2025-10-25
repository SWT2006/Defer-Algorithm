#pragma once
#include "Floorplan.h"

class EnumerativePacking {
public:
    // 为模块集合 [start, end) 生成 shape curve
    void generateAllLayouts(Floorplan &fp, int start, int end);

private:
    void mergeSubsets(Floorplan &fp, int idxA, int idxB, int parentIdx);
    void generatePermutations(Floorplan &fp, int start, int end, std::vector<int> &perm);
};
