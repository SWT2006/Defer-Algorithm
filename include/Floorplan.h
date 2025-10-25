#pragma once
#include <vector>
#include "Module.h"
#include "Net.h"

// Floorplan 表示一个当前子布局（子电路/模块组合）
class Floorplan {
private:
    std::vector<Module*> modules;   // 包含的模块
    double width;                    // floorplan 总宽
    double height;                   // floorplan 总高
    double x;                        // 左下角 x 坐标
    double y;                        // 左下角 y 坐标

public:
    Floorplan();
    Floorplan(const std::vector<Module*>& mods);
    void mergeCurves(int idxA, int idxB, int parentIdx);
    void addModule(Module* m);

    // 获取当前 floorplan 的尺寸
    double getWidth() const;
    double getHeight() const;

    // 设置 floorplan 左下角位置（用于 HPWL 计算）
    void setPosition(double x, double y);
    double getX() const;
    double getY() const;

    // 计算当前 floorplan 的 HPWL（考虑内部模块）
    double computeHPWL(const std::vector<Net*>& nets) const;

    const std::vector<Module*>& getModules() const;
};

