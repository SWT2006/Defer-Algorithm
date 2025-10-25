#include "Floorplan.h"
#include <algorithm>
#include <limits>

Floorplan::Floorplan() : width(0), height(0), x(0), y(0) {}

Floorplan::Floorplan(const std::vector<Module*>& mods) : modules(mods), x(0), y(0) {
    width = 0;
    height = 0;
    for (auto m : modules) {
        width = std::max(width, m->getWidth());
        height = std::max(height, m->getHeight());
    }
}

void Floorplan::addModule(Module* m) {
    modules.push_back(m);
    width = std::max(width, m->getWidth());
    height = std::max(height, m->getHeight());
}

double Floorplan::getWidth() const { return width; }
double Floorplan::getHeight() const { return height; }

void Floorplan::setPosition(double x, double y) {
    this->x = x;
    this->y = y;
    // 更新模块的坐标
    for (auto m : modules) {
        m->setPosition(x, y); // 简化处理，模块放在左下角
    }
}

double Floorplan::getX() const { return x; }
double Floorplan::getY() const { return y; }

const std::vector<Module*>& Floorplan::getModules() const {
    return modules;
}

double Floorplan::computeHPWL(const std::vector<Net*>& nets) const {
    double totalHPWL = 0.0;
    for (auto net : nets) {
        totalHPWL += net->computeHPWL();
    }
    return totalHPWL;
}
