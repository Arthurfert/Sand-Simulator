#include "Table.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <numeric>

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

void Table::addBubble(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height && grid[y][x] == 1) {
        grid[y][x] = 3; // Ajoute une bulle
    }
}

void Table::updateSand() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int y = height - 2; y >= 0; --y) { // Calcule de bas en haut
        // Crée une liste mélangée d'indices de colonnes
        std::vector<int> columns(width);
        std::iota(columns.begin(), columns.end(), 0); // Remplit avec 0, 1, ..., width-1
        std::shuffle(columns.begin(), columns.end(), gen); // Mélange les colonnes

        for (int x : columns) {
            if (grid[y][x] == 1) { // Si une particule de sable est présente
                // Vérifie si la particule peut tomber directement en bas
                if (y + 1 < height && (grid[y + 1][x] == 0 || grid[y + 1][x] == 3)) {
                    grid[y][x] = 0; // Efface la particule de sable
                    grid[y + 1][x] = 1; // Ajoute la particule de sable en bas
                }
                // Vérifie si une particule peut tomber en bas à gauche
                else if (y + 1 < height && x > 0 && (grid[y + 1][x - 1] == 0 || grid[y + 1][x - 1] == 3)) {
                    grid[y][x] = 0; // Efface la particule de sable
                    grid[y + 1][x - 1] = 1; // Ajoute la particule de sable en bas à gauche
                }
                // Vérifie si une particule peut tomber en bas à droite
                else if (y + 1 < height && x < width - 1 && (grid[y + 1][x + 1] == 0 || grid[y + 1][x + 1] == 3)) {
                    grid[y][x] = 0; // Efface la particule de sable
                    grid[y + 1][x + 1] = 1; // Ajoute la particule de sable en bas à droite
                }
            }
        }
    }
}

void Table::updateBubble() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int y = 1; y < height; ++y) { // Calcule de haut en bas
        // Crée une liste mélangée d'indices de colonnes
        std::vector<int> columns(width);
        std::iota(columns.begin(), columns.end(), 0); // Remplit avec 0, 1, ..., width-1
        std::shuffle(columns.begin(), columns.end(), gen); // Mélange les colonnes

        for (int x : columns) {
            if (grid[y][x] == 3) { // Si une bulle est présente
                // Génère un nombre aléatoire pour la direction du mouvement (-1, 0 ou 1)
                std::uniform_int_distribution<> dist(-1, 1);
                int direction = dist(gen);
                // Calcule la nouvelle position en fonction de cette direction
                int newX = x + direction;
                int newY = y - 1;

                // Vérifie si la nouvelle position est valide et si elle est occupée par du sable
                if (newY >= 0 && newX >= 0 && newX < width && grid[newY][newX] == 1) {
                    grid[y][x] = 1;       // Remplace la bulle par du sable
                    grid[newY][newX] = 3; // Ajoute la bulle à la nouvelle position
                }
            }
        }
    }
}

void Table::display() const {
    for (const auto& row : grid) {
        for (int cell : row) {
            if (cell == 1) {
                std::cout << "S "; // Sable
            } else if (cell == 2) {
                std::cout << "O "; // Obstacle
            } else if (cell == 3) {
                std::cout << "B "; // Bulle
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

void Table::clearCell(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = 0; // Efface la cellule
    }
}

void Table::clear() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0); // Efface toutes les cellules
    }
}