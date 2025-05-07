#include "Obstacle.h"

Obstacle::Obstacle(int x, int y) : x(x), y(y) {}

int Obstacle::getX() const {
    return x;
}

int Obstacle::getY() const {
    return y;
}

void Obstacle::update(Table& table, int x, int y, bool vide, int resistance) {
    // Les obstacles sont immobiles, donc aucune action n'est nécessaire ici.
}