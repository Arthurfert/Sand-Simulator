#pragma once
#include <SFML/Graphics.hpp>
#include "Table.h"
#include "Mouse.h"

class Affichage {
public:
    Affichage(int width, int height, int cellSize); // Constructeur
    void run(Table& table); // Boucle principale pour gérer l'affichage et les interactions
    void displayStatus(bool gomme, bool vide); // Affiche le statut de la simulation

private:
    void render(Table& table); // Méthode pour dessiner la grille

    sf::RenderWindow window; // Fenêtre SFML
    int width; // Largeur de la grille
    int height; // Hauteur de la grille
    int cellSize; // Taille d'une cellule
    Mouse mouse; // Objet pour gérer la position de la souris
};