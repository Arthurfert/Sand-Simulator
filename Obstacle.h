#pragma once
#include <SFML/Graphics.hpp>

class Obstacle {
public:
    Obstacle(int x, int y); // Constructeur avec position

    int getX() const;
    int getY() const;

private:
    int x; // Position X de l'obstacle
    int y; // Position Y de l'obstacle
};
