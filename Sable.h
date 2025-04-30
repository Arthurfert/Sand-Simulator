#pragma once
#include "Particule.h"

class Sable : public Particule {
public:
    Sable(int x = 0, int y = 0); // Constructeur par défaut
    int getX() const; // Accesseur pour x
    int getY() const; // Accesseur pour y
    void setPosition(int x, int y); // Modificateur pour x et y

    void update(class Table& table, int x, int y, bool vide) override; // Ajout de override

private:
    int x; // Coordonnée x du sable
    int y; // Coordonnée y du sable
};
