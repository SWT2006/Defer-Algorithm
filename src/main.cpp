#include <iostream>
#include <vector>
#include "Module.h"
#include "Net.h"
#include "Floorplan.h"

int main() {
    // 创建模块
    Module m1(1, 10, 20, false);
    Module m2(2, 15, 10, false);

    // 创建模块向量
    std::vector<Module*> modules = { &m1, &m2 };

    // 创建 floorplan
    Floorplan fp(modules);
    fp.setPosition(0, 0);

    std::cout << "Floorplan width: " << fp.getWidth() << "\n";
    std::cout << "Floorplan height: " << fp.getHeight() << "\n";

    // 示例 net（假设两个模块连一条 net）
    Net net1(1);
    net1.addModule(&m1);
    net1.addModule(&m2);
    std::vector<Net*> nets = { &net1 };

    std::cout << "HPWL: " << fp.computeHPWL(nets) << "\n";

    return 0;
}
