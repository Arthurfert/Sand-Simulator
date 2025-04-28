#include "Table.h"
#include "Sable.h"
#include "Bubble.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <numeric>

Table::Table(int width, int height) : width(width), height(height) {
    grid = std::vector<std::vector<std::shared_ptr<Particule>>>(height, std::vector<std::shared_ptr<Particule>>(width, nullptr));
}

void Table::addSable(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height && (!grid[y][x] || dynamic_cast<Bubble*>(grid[y][x].get()))) {
        grid[y][x] = std::make_shared<Sable>(x, y);
    }
}

void Table::addObstacle(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height && (!grid[y][x] || dynamic_cast<Bubble*>(grid[y][x].get()))) {
        grid[y][x] = std::make_shared<Obstacle>(x, y);
    }
}

void Table::addBubble(int x, int y) {
    if (x >= 0 && x < width && y >= 0 && y < height && grid[y][x] && dynamic_cast<Sable*>(grid[y][x].get())) {
        grid[y][x] = std::make_shared<Bubble>(x, y);
    }
}

std::shared_ptr<Particule> Table::getCell(int x, int y) const {
    return grid[y][x];
}

void Table::setCell(int x, int y, std::shared_ptr<Particule> particule) {
    grid[y][x] = particule;
}

void Table::moveParticle(int fromX, int fromY, int toX, int toY) {
    auto temp = grid[toY][toX]; // Stocke la particule temporairement
    grid[toY][toX] = grid[fromY][fromX];
    grid[fromY][fromX] = temp;
}

void Table::update() {
    std::random_device rd;
    std::mt19937 gen(rd());

    // Parcourir les lignes de bas en haut
    for (int y = height - 2; y >= 0; --y) {
        // Crée une liste mélangée d'indices de colonnes
        std::vector<int> columns(width);
        std::iota(columns.begin(), columns.end(), 0); // Remplit avec 0, 1, ..., width-1
        std::shuffle(columns.begin(), columns.end(), gen); // Mélange les colonnes

        // Parcourir les colonnes dans l'ordre mélangé
        for (int x : columns) {
            if (grid[y][x]) {
                // Appeler la méthode update spécifique à la particule
                grid[y][x]->update(*this, x, y);
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

int Table::getWidth() const {
    return width;
}

int Table::getHeight() const {
    return height;
}