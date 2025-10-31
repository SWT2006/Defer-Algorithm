#ifndef UTILS_H
#define UTILS_H

#include<bits/stdc++.h>

struct point{
    double x,y;
    point(double a, double b) : x(a), y(b) {}
};

struct Rect{//using the rectangle to represent the chiplet in the circuit board
    double x1,x2,y1,y2;// bottom-left (x1,y1) top-right (x2,y2);
    Rect(double a, double b, double c, double d) : x1(a), x2(b), y1(c), y2(d) {}
    double height(){// the height of rectangle is always positive,and the width below is either;
        return std::abs(y2 - y1);
    }
    double width(){
        return std::abs(x2 - x1);
    }
    point centre(){// center point of rectangle(x,y);
        return point((x1 + x2) / 2.0, (y1 + y2) / 2.0);
    }
    double area(){
        return width() * height();
    }
};


#endif // UTILS_H
