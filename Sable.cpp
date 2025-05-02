#include "Sable.h"
#include "Table.h"

Sable::Sable(int x, int y) : x(x), y(y) {}

int Sable::getX() const {
    return x;
}

int Sable::getY() const {
    return y;
}

int Sable::getV() const {
    return v;
}

void Sable::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}

void Sable::update(Table& table, int x, int y, bool vide, bool inertie) {
    if (vide) {
        if (y+1 > table.getHeight()-2) {
            table.clearCell(x,y);
            for (int i = 0; i < table.getWidth(); ++i) {
                table.clearCell(i, table.getHeight()-1);
            }
        } else if (y + 1 < table.getHeight() && !table.getCell(x, y + 1)) {
            table.moveParticle(x, y, x, y + 1);
        } else if (y + 1 < table.getHeight() && x > 0 && !table.getCell(x - 1, y + 1)) {
            table.moveParticle(x, y, x - 1, y + 1);
        } else if (y + 1 < table.getHeight() && x < table.getWidth() - 1 && !table.getCell(x + 1, y + 1)) {
            table.moveParticle(x, y, x + 1, y + 1);
        }
    } else {
        if (inertie) {
            // Logique avec inertie : le sable continue dans la même direction si possible
            if (y + 1 < table.getHeight() && !table.getCell(x, y + 1)) {
                table.moveParticle(x, y, x, y + 1);
            } else if (y + 1 < table.getHeight() && x > 0 && !table.getCell(x - 1, y + 1)) {
                table.moveParticle(x, y, x - 1, y + 1);
            } else if (y + 1 < table.getHeight() && x < table.getWidth() - 1 && !table.getCell(x + 1, y + 1)) {
                table.moveParticle(x, y, x + 1, y + 1);
            } else if (x > 0 && !table.getCell(x - 1, y) && getV()>0) {
                table.moveParticle(x, y, x - 1, y); // Mouvement horizontal gauche
                v-=1;
            } else if (x < table.getWidth() - 1 && !table.getCell(x + 1, y) && getV()>0) {
                table.moveParticle(x, y, x + 1, y); // Mouvement horizontal droite
                v-=1;
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
}