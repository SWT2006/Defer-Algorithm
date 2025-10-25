#include "EP.h"
#include <algorithm>
#include <vector>

void EnumerativePacking::generateAllLayouts(Floorplan &fp, int start, int end) {
    int n = end - start;
    if (n <= 1) return;

    // 对每个可能的子集划分递归生成
    for (int split = 1; split < n; ++split) {
        generateAllLayouts(fp, start, start + split);
        generateAllLayouts(fp, start + split, end);
        mergeSubsets(fp, start, start + split, start); // 合并为父节点
    }
}

void EnumerativePacking::mergeSubsets(Floorplan &fp, int idxA, int idxB, int parentIdx) {
    fp.mergeCurves(idxA, idxB, parentIdx);
}

void EnumerativePacking::generatePermutations(Floorplan &fp, int start, int end, std::vector<int> &perm) {
    std::sort(perm.begin(), perm.end());
    do {
        // 可以在这里生成 shape curve 对应于当前排列
        // 用 mergeCurves 处理
    } while (std::next_permutation(perm.begin(), perm.end()));
}
