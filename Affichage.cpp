#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <filesystem>
#include "Affichage.h"
#include "Table.h"
#include "Mouse.h"
#include "Particule.h"

Affichage::Affichage(int width, int height, int cellSize)
    : width(width), height(height), cellSize(cellSize),
      window(sf::VideoMode(width * cellSize, height * cellSize), "Simulation de sable") {
    window.setFramerateLimit(60);
}

void Affichage::run(Table& table) {
    bool gomme = false; // Gomme activé ou non (false = non, true = oui)
    bool vide = false; // Vide activé ou non (false = non, true = oui)
    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Detecte la pression de la touche 'D' pour effacer le tableau
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
                table.clear(); // Efface le tableau
            }
            // Detecte la pression de la touche 'G' pour activer/désactiver la gomme
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::G) {
                gomme = !gomme; // Active ou désactive la gomme
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::V) {
                vide = !vide; // Active ou désactive le vide
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
            table.update(vide);
        } else {
            // Ajoute du sable avec un clic gauche
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i gridPos = mouse.getGridPosition(cellSize);

                // Défini une zone autour de la position de la souris
                int zoneSize = 3; // Taille de la zone, 3x3 pixels

                // Générateur de nombres aléatoires
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<int> distX(-zoneSize, zoneSize);
                std::uniform_int_distribution<int> distY(-zoneSize, zoneSize);

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
            table.update(vide);
        }

        // Efface la fenêtre
        window.clear(sf::Color::Black);

        // Dessine la grille
        render(table);

        // Affiche le contenu de la fenêtre
        window.display();
    }
}

void Affichage::render(Table& table) {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Crée un rectangle pour chaque cellule de la grille
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(static_cast<float>(x * cellSize), static_cast<float>(y * cellSize));

            // Défini la couleur de la cellule en fonction de son contenu
            auto& cellContent = table.getGrid()[y][x];
            if (cellContent && dynamic_cast<Sable*>(cellContent.get())) {
                cell.setFillColor(sf::Color::Yellow); // Sable
            } else if (cellContent && dynamic_cast<Obstacle*>(cellContent.get())) {
                cell.setFillColor(sf::Color(128, 128, 128)); // Obstacle
            } else {
                continue; // Cellule vide, ne rien dessiner
            }

            // Dessine la cellule
            window.draw(cell);
        }
    }
}
