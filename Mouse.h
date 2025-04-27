#pragma once
#include <SFML/Graphics.hpp>

class Mouse {
public:
    Mouse();

    void update(const sf::RenderWindow& window); // Met à jour la position de la souris

    sf::Vector2i getGridPosition(int cellSize) const; // Récupère la position de la souris dans la grille

private:
    sf::Vector2i position; // Position de la souris en pixels
};
