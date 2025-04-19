#pragma once

class Sable {
public:
    Sable(); // Constructeur par défaut
    Sable(int x, int y); // Constructeur avec position

    int getX() const;
    int getY() const;
    void setPosition(int x, int y);

private:
    int x; // Position X de la particule
    int y; // Position Y de la particule
};
