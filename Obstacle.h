#pragma once
#include "Particule.h"

class Obstacle : public Particule {
public:
    Obstacle(int x = 0, int y = 0); // Constructeur par défaut
    int getX() const; // Accesseur pour x
    int getY() const; // Accesseur pour y

private:
    int x; // Coordonnée x de l'obstacle
    int y; // Coordonnée y de l'obstacle
};
