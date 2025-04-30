#include "Sable.h"
#include "Table.h"

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

void Sable::update(Table& table, int x, int y, bool vide) {
    if (vide) {
        if (y+1 > table.getHeight()-1) {
            table.clearCell(x,y);
        } else if (y + 1 < table.getHeight() && !table.getCell(x, y + 1)) {
            table.moveParticle(x, y, x, y + 1);
        } else if (y + 1 < table.getHeight() && x > 0 && !table.getCell(x - 1, y + 1)) {
            table.moveParticle(x, y, x - 1, y + 1);
        } else if (y + 1 < table.getHeight() && x < table.getWidth() - 1 && !table.getCell(x + 1, y + 1)) {
            table.moveParticle(x, y, x + 1, y + 1);
        }
    } else {
        if (y + 1 < table.getHeight() && !table.getCell(x, y + 1)) {
            table.moveParticle(x, y, x, y + 1);
        } else if (y + 1 < table.getHeight() && x > 0 && !table.getCell(x - 1, y + 1)) {
            table.moveParticle(x, y, x - 1, y + 1);
        } else if (y + 1 < table.getHeight() && x < table.getWidth() - 1 && !table.getCell(x + 1, y + 1)) {
            table.moveParticle(x, y, x + 1, y + 1);
        }
    }
}