#pragma once
#include <vector>
#include "Module.h"

class Net {
private:
    int id;
    std::vector<Module*> modules;  // 该网连接的模块指针

public:
    Net(int id);
    std::vector<int> pins; 
    void addModule(Module* m);     // 添加模块到网
    const std::vector<Module*>& getModules() const;

    // 计算半周长线长度（HPWL）
    double computeHPWL() const;

    int getId() const;
};
