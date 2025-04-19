#pragma once
#include <vector>
#include "Sable.h"

class Table {
public:
    Table(int width, int height);

    void addSable(int x, int y);
    void update(); // Met à jour la simulation
    void display() const; // Affiche l'état du tableau (console ou graphique)

    const std::vector<std::vector<int>>& getGrid() const; // Accesseur pour grid

private:
    int width;
    int height;
    std::vector<std::vector<int>> grid; // 0 = vide, 1 = sable
};
