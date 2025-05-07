#pragma once
#include "Particule.h"

class Sable : public Particule {
public:
    Sable(int x = 0, int y = 0); // Constructeur par défaut
    int getX() const; // Accesseur pour x
    int getY() const; // Accesseur pour y

    bool getM() const override;// Accesseur pour isMoving
    void update(class Table& table, int x, int y, bool vide, int resistance) override; // Ajout de override

private:
    int x; // Coordonnée x du sable
    int y; // Coordonnée y du sable
    bool isMoving = true; // inertie
};
