#include "Mouse.h"

Mouse::Mouse() : position(0, 0) {}

void Mouse::update(const sf::RenderWindow& window) {
    // Récupère la position globale de la souris (sert pour que cela fonctionne en mode plien écran)
    sf::Vector2i globalPosition = sf::Mouse::getPosition();

    // Convertit la position globale en position relative à la fenêtre
    sf::Vector2f relativePosition = window.mapPixelToCoords(globalPosition);

    // Met à jour la position en pixels
    position = sf::Vector2i(static_cast<int>(relativePosition.x), static_cast<int>(relativePosition.y));
}

sf::Vector2i Mouse::getGridPosition(int cellSize) const {
    // Convertit la position en pixels en coordonnées de la grille
    return sf::Vector2i(position.x / cellSize, position.y / cellSize);
}