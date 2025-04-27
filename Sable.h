#pragma once

class Sable {
public:
    Sable(); // Constructeur par défaut
    Sable(int x, int y); // Constructeur avec position
    int getX() const; // Accesseur pour la position X
    int getY() const; // Accesseur pour la position Y
    void setPosition(int x, int y); // Mutateur pour la position

private:
    int x; // Position X de la particule
    int y; // Position Y de la particule
};
