#include "Bubble.h"
#include "Table.h"
#include "Sable.h"
#include <random>

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

void Bubble::update(Table& table, int x, int y) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-1, 1);

    int direction = dist(gen);
    int newX = x + direction;
    int newY = y - 1;

    if (newY >= 0 && newX >= 0 && newX < table.getWidth() && dynamic_cast<Sable*>(table.getCell(newX, newY).get())) {
        table.moveParticle(x, y, newX, newY);
    }
}