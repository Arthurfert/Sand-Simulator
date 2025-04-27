#include "Bubble.h"

Bubble::Bubble(int x, int y) : x(x), y(y) {}

int Bubble::getX() const {
    return x;
}

int Bubble::getY() const {
    return y;
}

void Bubble::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}