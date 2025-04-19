#include "Mouse.h"

Mouse::Mouse() : position(0, 0) {}

void Mouse::update(const sf::RenderWindow& window) {
    // Récupère la position de la souris relative à la fenêtre
    position = sf::Mouse::getPosition(window);
}

sf::Vector2i Mouse::getGridPosition(int cellSize) const {
    // Convertit la position en pixels en coordonnées de la grille
    return sf::Vector2i(position.x / cellSize, position.y / cellSize);
}