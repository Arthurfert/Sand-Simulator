#include "Table.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <numeric>

Table::Table(int width, int height) : width(width), height(height) {
    grid = std::vector<std::vector<std::shared_ptr<Particule>>>(height, std::vector<std::shared_ptr<Particule>>(width, nullptr));
}

void Table::addSable(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height && !grid[y][x]) {
        grid[y][x] = std::make_shared<Sable>(x, y);
    }
}

void Table::addObstacle(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height && !grid[y][x]) {
        grid[y][x] = std::make_shared<Obstacle>(x, y);
    }
}

void Table::addBubble(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height && grid[y][x] && dynamic_cast<Sable*>(grid[y][x].get())) {
        grid[y][x] = std::make_shared<Bubble>(x, y);
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
            if (grid[y][x] && dynamic_cast<Sable*>(grid[y][x].get())) {
                if (y + 1 < height && (!grid[y + 1][x] || dynamic_cast<Bubble*>(grid[y + 1][x].get()))) {
                    grid[y + 1][x] = grid[y][x];
                    grid[y][x] = nullptr;
                } else if (y + 1 < height && x > 0 && (!grid[y + 1][x - 1] || dynamic_cast<Bubble*>(grid[y + 1][x - 1].get()))) {
                    grid[y + 1][x - 1] = grid[y][x];
                    grid[y][x] = nullptr;
                } else if (y + 1 < height && x < width - 1 && (!grid[y + 1][x + 1] || dynamic_cast<Bubble*>(grid[y + 1][x + 1].get()))) {
                    grid[y + 1][x + 1] = grid[y][x];
                    grid[y][x] = nullptr;
                }
            }
        }
    }
}

void Table::updateBubble() {
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int y = 1; y < height; ++y) {
        std::vector<int> columns(width);
        std::iota(columns.begin(), columns.end(), 0);
        std::shuffle(columns.begin(), columns.end(), gen);

        for (int x : columns) {
            if (grid[y][x] && dynamic_cast<Bubble*>(grid[y][x].get())) {
                std::uniform_int_distribution<> dist(-1, 1);
                int direction = dist(gen);
                int newX = x + direction;
                int newY = y - 1;

                if (newY >= 0 && newX >= 0 && newX < width && grid[newY][newX] && dynamic_cast<Sable*>(grid[newY][newX].get())) {
                    grid[newY][newX] = std::make_shared<Bubble>(newX, newY);
                    grid[y][x] = std::make_shared<Sable>(x, y); // Remplace la bulle par du sable
                }
            }
        }
    }
}

const std::vector<std::vector<std::shared_ptr<Particule>>>& Table::getGrid() const {
    return grid;
}

void Table::clearCell(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        grid[y][x] = nullptr;
    }
}

void Table::clear() {
    for (auto& row : grid) {
        std::fill(row.begin(), row.end(), nullptr);
    }
}