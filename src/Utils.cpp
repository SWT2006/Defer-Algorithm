#include "Utils.h"
#include <algorithm>
#include <limits>
int computeHPWL(const std::vector<Module>& modules, const std::vector<Net>& nets) {
    int totalHPWL = 0;
    for (auto &net : nets) {
        int xmin = std::numeric_limits<int>::max();
        int xmax = std::numeric_limits<int>::min();
        int ymin = std::numeric_limits<int>::max();
        int ymax = std::numeric_limits<int>::min();
        for (int idx : net.pins) {
            xmin = std::min(xmin, static_cast<int>(modules[idx].getX()));
            xmax = std::max(xmax, static_cast<int>(modules[idx].getX() + modules[idx].getWidth()));
            ymin = std::min(ymin, static_cast<int>(modules[idx].getY()));
            ymax = std::max(ymax, static_cast<int>(modules[idx].getY() + modules[idx].getHeight()));


        }
        totalHPWL += (xmax - xmin) + (ymax - ymin);
    }
    return totalHPWL;
}
