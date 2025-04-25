#include "Gomme.h"

Gomme::Gomme() : x(0), y(0) {}

Gomme::Gomme(int x, int y) : x(x), y(y) {}

int Gomme::getX() const {
    return x;
}

int Gomme::getY() const {
    return y;
}

void Gomme::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}