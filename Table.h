#pragma once
#include <vector>
#include <numeric>

class Table {
public:
    Table(int width, int height); // Constructeur qui initialise la grille avec des zéros (cellules vides)
    void addSable(int x, int y); // Ajoute une particule de sable à la position (x, y)
    void addObstacle(int x, int y); // Ajoute un obstacle à la position (x, y)
    void addBubble(int x, int y); // Ajoute une bulle à la position (x, y)
    void updateSand(); // Met à jour la position des particules de sable
    void updateBubble(); // Met à jour la position des bulles
    void display() const; // Affiche la grille dans la console (pour le débogage)
    void clearCell(int x, int y); // Efface la cellule à la position (x, y)
    void clear(); // Efface toute la grille

    const std::vector<std::vector<int>>& getGrid() const; // Accesseur pour obtenir la grille

private:
    int width; // Largeur de la grille
    int height; // Hauteur de la grille
    std::vector<std::vector<int>> grid; // Grille de simulation
};
