#include "Table.h"
#include <iostream>

Table::Table(int width, int height) : width(width), height(height) {
    grid = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
}

void Table::addSable(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height && grid[y][x] == 0) {
        grid[y][x] = 1; // Ajoute une particule de sable
    }
}

void Table::addObstacle(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height && grid[y][x] == 0) {
        grid[y][x] = 2; // Ajoute un obstacle
    }
}

void Table::update() {
    for (int y = height - 2; y >= 0; --y) { // Parcours de bas en haut
        for (int x = 0; x < width; ++x) {
            if (grid[y][x] == 1) { // Si une particule de sable est présente
                // Vérifie si la particule peut descendre
                if (grid[y + 1][x] == 0) {
                    // Déplace la particule de sable vers le bas
                    grid[y][x] = 0;
                    grid[y + 1][x] = 1;
                } else if (x > 0 && grid[y + 1][x - 1] == 0) {
                    // Déplace la particule de sable vers le bas à gauche
                    grid[y][x] = 0;
                    grid[y + 1][x - 1] = 1;
                } else if (x < width - 1 && grid[y + 1][x + 1] == 0) {
                    // Déplace la particule de sable vers le bas à droite
                    grid[y][x] = 0;
                    grid[y + 1][x + 1] = 1;
                }
                // Si la cellule en dessous est un obstacle ou une autre particule, le sable reste en place
            }
        }
    }
}

void Table::display() const {
    for (const auto& row : grid) {
        for (int cell : row) {
            if (cell == 1) {
                std::cout << "# "; // Sable
            } else if (cell == 2) {
                std::cout << "O "; // Obstacle
            } else {
                std::cout << ". "; // Vide
            }
        }
        std::cout << std::endl;
    }
}

const std::vector<std::vector<int>>& Table::getGrid() const {
    return grid;
}