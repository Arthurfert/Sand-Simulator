#pragma once
#include "Particule.h"

class Bubble : public Particule {
public:
    Bubble(int x = 0, int y = 0); // Default and parameterized constructor
    int getX() const;
    int getY() const;
    void setPosition(int x, int y);

private:
    int x;
    int y;
};