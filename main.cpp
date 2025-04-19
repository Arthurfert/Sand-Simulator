#include <SFML/Graphics.hpp>
#include <iostream>
#include "Table.h"

int main() {
    int width = 500, height = 500, cellSize = 1;
    std::cout << "Bienvenue dans la simulation de sable !" << std::endl;
    std::cout << "Veuillez entrer la largeur du tableau : ";
    std::cin >> width;
    std::cout << "Veuillez entrer la hauteur du tableau : ";
    std::cin >> height;

    Table table(width, height);

    // Ajout de particules de sable pour tester
    table.addSable(10, 0);
    table.addSable(10, 1);
    table.addSable(10, 2);
    table.addSable(11, 0);
    table.addSable(11, 1);

    // Création de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(width * cellSize, height * cellSize), "Simulation de sable");
    window.setFramerateLimit(60);

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Met à jour la simulation
        table.update();

        // Efface la fenêtre
        window.clear(sf::Color::Black);

        // Dessine la grille
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (table.getGrid()[y][x] == 1) { // Utilisation de getGrid()
                    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                    cell.setPosition(x * cellSize, y * cellSize);
                    cell.setFillColor(sf::Color::Yellow);
                    window.draw(cell);
                }
            }
        }

        // Affiche le contenu de la fenêtre
        window.display();
    }

    return 0;
}