#include <iostream>
#include "Table.h"
#include "Affichage.h"

int main() {
    int width = 150, height = 150, cellSize = 1; // Paramètres par défaut
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "             Sand Simulation by Arthur FERT               " << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "Utilisez la souris pour interagir avec le tableau :" << std::endl;
    std::cout << "Ajouter du sable avec un clic gauche." << std::endl;
    std::cout << "Ajouter un obstacle avec un clic droit." << std::endl;
    std::cout << "Appuyez sur 'd' (delete) pour effacer le tableau." << std::endl;
    std::cout << "Appuyez sur 'g' pour activer/désactiver la gomme." << std::endl;
    std::cout << "----------------------------------------------------------" << std::endl;
    std::cout << "Veuillez entrer la largeur du tableau : ";
    std::cin >> width;
    std::cout << "Veuillez entrer la hauteur du tableau : ";
    std::cin >> height;

    Table table(width, height); // Création de la grille vide
    Affichage affichage(width, height, cellSize); // Création de l'objet d'affichage

    // Lancement de la boucle principale
    affichage.run(table);

    return 0;
}