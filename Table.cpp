#include "Table.h"
#include <iostream>
#include <algorithm> // For std::shuffle
#include <random>    // For random number generation
#include <numeric>   // For std::iota

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

    for (int y = height - 2; y >= 0; --y) { // Process rows from bottom to top
        // Create a shuffled list of column indices
        std::vector<int> columns(width);
        std::iota(columns.begin(), columns.end(), 0); // Fill with 0, 1, ..., width-1
        std::shuffle(columns.begin(), columns.end(), gen);

        for (int x : columns) { // Process columns in random order
            if (grid[y][x] == 1) { // If a sand particle is present
                // Check if the particle can fall straight down
                if (y + 1 < height && (grid[y + 1][x] == 0 || grid[y + 1][x] == 3)) {
                    grid[y][x] = 0;
                    grid[y + 1][x] = 1;
                }
                // Check if the particle can fall down-left
                else if (y + 1 < height && x > 0 && (grid[y + 1][x - 1] == 0 || grid[y + 1][x - 1] == 3)) {
                    grid[y][x] = 0;
                    grid[y + 1][x - 1] = 1;
                }
                // Check if the particle can fall down-right
                else if (y + 1 < height && x < width - 1 && (grid[y + 1][x + 1] == 0 || grid[y + 1][x + 1] == 3)) {
                    grid[y][x] = 0;
                    grid[y + 1][x + 1] = 1;
                }
            } 
        }
    }
}

void Table::updateBubble() {
    std::random_device rd;
    std::mt19937 gen(rd());
    for (int y = 0; y <= height-2; ++y) { // Process rows from bottom to top
        // Create a shuffled list of column indices
        std::vector<int> columns(width);
        std::iota(columns.begin(), columns.end(), 0); // Fill with 0, 1, ..., width-1
        std::shuffle(columns.begin(), columns.end(), gen);

        for (int x : columns) { // Process columns in random order
            if (grid[y][x] == 3) { // If a bubble is present
                // Check if the bubble can rise straight up
                if (y - 1 >= 0 && grid[y - 1][x] == 1) {
                    grid[y][x] = 1;
                    grid[y - 1][x] = 3;
                }
                // Check if the bubble can rise up-left
                else if (y - 1 >= 0 && x > 0 && grid[y - 1][x - 1] == 1) {
                    grid[y][x] = 1;
                    grid[y - 1][x - 1] = 3;
                }
                // Check if the bubble can rise up-right
                else if (y - 1 >= 0 && x < width - 1 && grid[y - 1][x + 1] == 1) {
                    grid[y][x] = 1;
                    grid[y - 1][x + 1] = 3;
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

void Table::clear() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), 0); // Set all cells to 0 (empty)
    }
}