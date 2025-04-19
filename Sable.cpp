#include "Sable.h"

Sable::Sable() : x(0), y(0) {}

Sable::Sable(int x, int y) : x(x), y(y) {}

int Sable::getX() const {
    return x;
}

int Sable::getY() const {
    return y;
}

void Sable::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}