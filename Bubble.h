#pragma once
#include "Particule.h"

class Bubble : public Particule {
public:
    Bubble(int x = 0, int y = 0); // Constructeur par défaut
    int getX() const; // Accesseur pour x
    int getY() const; // Accesseur pour y
    void setPosition(int x, int y); // Modificateur pour x et y

private:
    int x; // Coordonnée x de la bulle
    int y; // Coordonnée y de la bulle
};