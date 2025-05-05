#pragma once
#include <vector>
#include <memory>
#include "Sable.h"
#include "Obstacle.h"

class Table {
public:
    Table(int width, int height); // Constructeur qui initialise la grille avec des zéros (cellules vides)
    void addSable(int x, int y); // Ajoute une particule de sable à la position (x, y)
    void addObstacle(int x, int y); // Ajoute un obstacle à la position (x, y)
    void addInertiaSable(int x, int y); // Ajoute une particule de sable avec inertie à la position (x, y)
    void update(bool vide); // Met à jour la position des particules
    void clearCell(int x, int y); // Efface la cellule à la position (x, y)
    void clear(); // Efface toute la grille

    const std::vector<std::vector<std::shared_ptr<Particule>>>& getGrid() const; // Accesseur pour la grille
    int getWidth() const; // Retourne la largeur de la grille
    int getHeight() const; // Retourne la hauteur de la grille
    std::shared_ptr<Particule> getCell(int x, int y) const; // Retourne la particule à une position donnée
    void setCell(int x, int y, std::shared_ptr<Particule> particule); // Définit une particule à une position donnée
    void moveParticle(int fromX, int fromY, int toX, int toY); // Déplace une particule d'une position à une autre

private:
    int width; // Largeur de la grille
    int height; // Hauteur de la grille
    std::vector<std::vector<std::shared_ptr<Particule>>> grid; // Grille de particules
};
