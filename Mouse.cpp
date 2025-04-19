#include "Mouse.h"

Mouse::Mouse() : position(0, 0) {}

void Mouse::update(const sf::RenderWindow& window) {
    // Récupère la position de la souris relative à la fenêtre
    sf::Vector2i pixelPosition = sf::Mouse::getPosition(window);

    // Convertit la position en coordonnées de la fenêtre
    sf::Vector2f worldPosition = window.mapPixelToCoords(pixelPosition);

    // Met à jour la position en pixels (arrondi pour rester cohérent avec la grille)
    position = sf::Vector2i(static_cast<int>(worldPosition.x), static_cast<int>(worldPosition.y));
}

sf::Vector2i Mouse::getGridPosition(int cellSize) const {
    // Convertit la position en pixels en coordonnées de la grille
    return sf::Vector2i(position.x / cellSize, position.y / cellSize);
}