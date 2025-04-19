#pragma once
#include <SFML/Graphics.hpp>

class Mouse {
public:
    Mouse();

    // Met à jour la position de la souris
    void update(const sf::RenderWindow& window);

    // Retourne la position de la souris en coordonnées de la grille
    sf::Vector2i getGridPosition(int cellSize) const;

private:
    sf::Vector2i position; // Position de la souris en pixels    sf::Vector2i position; // Position de la souris en pixels
};
