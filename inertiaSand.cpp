#include "inertiaSand.h"
#include "Table.h"
#include <random>

inertiaSand::inertiaSand(int x, int y) : x(x), y(y) {}

int inertiaSand::getX() const {
    return x;
}

int inertiaSand::getY() const {
    return y;
}

bool inertiaSand::getM() const {
    return isMoving;
}

void inertiaSand::update(Table& table, int x, int y, bool vide, int resistance) {
    if (x - 1 < 0 || x + 1 >= table.getWidth() || y - 1 < 0 || y + 1 >= table.getHeight()) {
        table.clearCell(x, y); // Pas de bords latéraux
        return;
    }
    // Suppression des particules si le vide est activé et que la particule est en bas
    if (vide && y + 1 > table.getHeight() - 2) {
        table.clearCell(x, y);
        for (int i = 0; i < table.getWidth(); ++i) {
            table.clearCell(i, table.getHeight() - 1);
        }
        return;
    }

    if (isMoving) {
        // Si la particule est en mouvement, on la déplace
        if (y + 1 < table.getHeight() && !table.getCell(x, y + 1)) {
            table.moveParticle(x, y, x, y + 1);
        } else if (y + 1 < table.getHeight() && x > 0 && !table.getCell(x - 1, y + 1)) {
            table.moveParticle(x, y, x - 1, y + 1);
        } else if (y + 1 < table.getHeight() && x < table.getWidth() - 1 && !table.getCell(x + 1, y + 1)) {
            table.moveParticle(x, y, x + 1, y + 1);
        } else {
            // Si la particule ne peut pas se déplacer, on la fixe
            isMoving = false;
        }
    } else {
        // Définition du test random(0,1)
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0, 10);

        double randomValue = dis(gen);
        double res = resistance; // Résistance de 0 à 10
        // test de la résistance
        if (randomValue > res) {
            if (x > 0 && x < table.getWidth() - 1) {
                auto leftCell = table.getCell(x - 1, y);
                auto rightCell = table.getCell(x + 1, y);

                if ((leftCell && leftCell->getM()) || (rightCell  && rightCell->getM()) || !table.getCell(x, y + 1)) {
                    isMoving = true; // Si les particules adjacentes bougent, on se remet en mouvement
                }
            }
        }
        if (y + 1 < table.getHeight() && !table.getCell(x, y + 1)) {
            table.moveParticle(x, y, x, y + 1);
            isMoving = true; // On remet la particule en mouvement si elle descend
        }
    }
}