#pragma once
#include <vector>
#include <memory>
#include "Sable.h"
#include "Obstacle.h"
#include "Bubble.h"

class Table {
public:
    Table(int width, int height); // Constructeur qui initialise la grille avec des zéros (cellules vides)
    void addSable(int x, int y); // Ajoute une particule de sable à la position (x, y)
    void addObstacle(int x, int y); // Ajoute un obstacle à la position (x, y)
    void addBubble(int x, int y); // Ajoute une bulle à la position (x, y)
    void updateSand(); // Met à jour la position des particules de sable
    void updateBubble(); // Met à jour la position des bulles
    void clearCell(int x, int y); // Efface la cellule à la position (x, y)
    void clear(); // Efface toute la grille

    const std::vector<std::vector<std::shared_ptr<Particule>>>& getGrid() const; // Accesseur pour la grille

private:
    int width; // Largeur de la grille
    int height; // Hauteur de la grille
    std::vector<std::vector<std::shared_ptr<Particule>>> grid; // Grille de particules
};
