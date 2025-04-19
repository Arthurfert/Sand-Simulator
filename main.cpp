#include <SFML/Graphics.hpp>
#include <iostream>
#include "Table.h"
#include "Mouse.h"

int main() {
    int width = 150, height = 150, cellSize = 1;
    std::cout << "Bienvenue dans la simulation de sable !" << std::endl;
    std::cout << "Veuillez entrer la largeur du tableau : ";
    std::cin >> width;
    std::cout << "Veuillez entrer la hauteur du tableau : ";
    std::cin >> height;

    Table table(width, height);
    Mouse mouse;

    // Création de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(width, height), "Simulation de sable");
    window.setFramerateLimit(60);

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Met à jour la position de la souris
        mouse.update(window);

        // Ajoute du sable avec un clic gauche
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i gridPos = mouse.getGridPosition(cellSize);
            if (gridPos.x >= 0 && gridPos.x < width && gridPos.y >= 0 && gridPos.y < height) {
                table.addSable(gridPos.x, gridPos.y);
            }
        }

        // Ajoute un obstacle avec un clic droit
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2i gridPos = mouse.getGridPosition(cellSize);
            if (gridPos.x >= 0 && gridPos.x < width && gridPos.y >= 0 && gridPos.y < height) {
                table.addObstacle(gridPos.x, gridPos.y);
            }
        }

        // Met à jour la simulation
        table.update();

        // Efface la fenêtre
        window.clear(sf::Color::Black);

        // Dessine la grille
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(x, y);

                if (table.getGrid()[y][x] == 1) {
                    cell.setFillColor(sf::Color::Yellow); // Sable
                } else if (table.getGrid()[y][x] == 2) {
                    cell.setFillColor(sf::Color(128, 128, 128)); // Obstacle
                } else {
                    continue; // Vide
                }

                window.draw(cell);
            }
        }

        // Affiche le contenu de la fenêtre
        window.display();
    }

    return 0;
}