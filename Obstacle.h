#pragma once
#include "Particule.h"

class Obstacle : public Particule {
public:
    Obstacle(int x = 0, int y = 0); // Default and parameterized constructor
    int getX() const;
    int getY() const;

private:
    int x;
    int y;
};
