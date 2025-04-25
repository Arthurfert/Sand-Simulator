#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include "Table.h"
#include "Mouse.h"

int main() {
    int width = 150, height = 150, cellSize = 1;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "             Sand Simulation by Arthur FERT               " << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "Utilisez la souris pour interagir avec le tableau :" << std::endl;
    std::cout << "Ajouter du sable avec un clic gauche." << std::endl;
    std::cout << "Ajouter un obstacle avec un clic droit." << std::endl;
    std::cout << "Appuyez sur 'd' (delete) pour effacer le tableau." << std::endl;
    std::cout << "Appuyez sur 'c' pour changer le type de particules (sable ou bulle)." << std::endl;
    std::cout << "Appuyez sur 'g' pour activer/désactiver la gomme." << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "Veuillez entrer la largeur du tableau : ";
    std::cin >> width;
    std::cout << "Veuillez entrer la hauteur du tableau : ";
    std::cin >> height;

    Table table(width, height);
    Mouse mouse;

    // Création de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(width, height), "Simulation de sable");
    window.setFramerateLimit(60);
    
    bool type = true; // Type de particule (false = bulle, true = sable)
    bool gomme = false; // Gomme activé ou non (false = non, true = oui)
    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Detecte la pression de la touche 'C' pour effacer le tableau
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
                table.clear(); // Efface le tableau
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) {
                type = !type; // Change le type de particules
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G) {
                gomme = !gomme; // Active ou désactive la gomme
            }
        }

        // Met à jour la position de la souris
        mouse.update(window);

        // Ajoute un obstacle avec un clic droit
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
            sf::Vector2i gridPos = mouse.getGridPosition(cellSize);

            // Vérifie que la position centrale est dans les limites de la grille
            if (gridPos.x >= 0 && gridPos.x < width && gridPos.y >= 0 && gridPos.y < height) {
                // Ajoute un bloc de 2 pixels de large
                for (int offset = 0; offset < 3; ++offset) {
                    int newX = gridPos.x + offset;
                    int newY = gridPos.y + offset;
                    // Vérifie que la position générée est dans les limites de la grille
                    if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                        // Ajoute un obstacle à la position générée
                        table.addObstacle(newX, newY);
                    }
                }
            }
        }

        if (gomme) {
            // Efface une cellule avec un clic gauche
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i gridPos = mouse.getGridPosition(cellSize);

                // Vérifie que la position centrale est dans les limites de la grille
                if (gridPos.x >= 0 && gridPos.x < width && gridPos.y >= 0 && gridPos.y < height) {
                    // Efface la cellule à la position générée
                    table.clearCell(gridPos.x, gridPos.y);
                }
            }
            table.updateSand();
        } else {
            if (type){
                // Ajoute du sable avec un clic gauche
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i gridPos = mouse.getGridPosition(cellSize);

                    // Définir une zone autour de la position de la souris
                    int zoneSize = 3; // Taille de la zone (par exemple, 3x3 autour de la souris)

                    // Générateur de nombres aléatoires
                    std::random_device rd;
                    std::mt19937 gen(rd());
                    std::uniform_int_distribution<> distX(-zoneSize, zoneSize);
                    std::uniform_int_distribution<> distY(-zoneSize, zoneSize);

                    // Générer plusieurs particules dans la zone
                    for (int i = 0; i < 5; ++i) { // 5 particules par clic
                        int offsetX = distX(gen);
                        int offsetY = distY(gen);

                        int newX = gridPos.x + offsetX;
                        int newY = gridPos.y + offsetY;

                        // Vérifie que la position générée est dans les limites de la grille
                        if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                            table.addSable(newX, newY);
                        }
                    }
                }
                // Met à jour la simulation
                table.updateSand();
            } else {
                // Ajoute une bulle avec un clic gauche
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i gridPos = mouse.getGridPosition(cellSize);

                    // Vérifie que la position centrale est dans les limites de la grille
                    if (gridPos.x >= 0 && gridPos.x < width && gridPos.y >= 0 && gridPos.y < height) {
                        // Ajoute une bulle à la position générée
                        table.addBubble(gridPos.x, gridPos.y);
                    }
                }
                // Met à jour la simulation
                table.updateBubble();
            }
        }

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
                } else if (table.getGrid()[y][x] == 3) {
                    cell.setFillColor(sf::Color(0, 0, 0)); // Bulle
                } else {
                    continue; // Cellule vide
                }

                window.draw(cell);
            }
        }

        // Affiche le contenu de la fenêtre
        window.display();
    }

    return 0;
}