#include "Obstacle.h"

Obstacle::Obstacle(int x, int y) : x(x), y(y) {}

int Obstacle::getX() const {
    return x;
}

int Obstacle::getY() const {
    return y;
}