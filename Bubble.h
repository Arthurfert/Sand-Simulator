#pragma once
#include "Particule.h"

class Bubble : public Particule {
public:
    Bubble(int x = 0, int y = 0); // Constructeur par défaut
    int getX() const; // Accesseur pour x
    int getY() const; // Accesseur pour y
    void setPosition(int x, int y); // Modificateur pour x et y

    void update(class Table& table, int x, int y) override; // Ajout de override

private:
    int x; // Coordonnée x de la bulle
    int y; // Coordonnée y de la bulle
};