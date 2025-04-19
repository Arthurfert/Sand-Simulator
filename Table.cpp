#include "Table.h"
#include <iostream>

Table::Table(int width, int height) : width(width), height(height) {
    grid = std::vector<std::vector<int>>(height, std::vector<int>(width, 0));
}

void Table::addSable(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = 1; // Ajoute une particule de sable
    }
}

void Table::update() {
    for (int y = height - 2; y >= 0; --y) { // Parcours de bas en haut
        for (int x = 0; x < width; ++x) {
            if (grid[y][x] == 1 && grid[y + 1][x] == 0) {
                // Déplace la particule de sable vers le bas
                grid[y][x] = 0;
                grid[y + 1][x] = 1;
            }
        }
    }
}

void Table::display() const {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell == 1 ? "#" : ".") << " ";
        }
        std::cout << std::endl;
    }
}

const std::vector<std::vector<int>>& Table::getGrid() const {
    return grid;
}