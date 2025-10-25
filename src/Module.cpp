#pragma once

class Module {
private:
    int id;
    double width, height;
    bool isSoft;
    double x, y;

public:
    Module(int id, double w, double h, bool isSoft);

    double getWidth() const;
    double getHeight() const;
    bool isSoftModule() const;
    int getId() const;

    void setPosition(double x, double y);
    double getX() const;
    double getY() const;
};
