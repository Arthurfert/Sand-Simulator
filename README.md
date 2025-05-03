# Sand-Simulator

A school project to learn object-oriented coding.

## Precise description

This project simulate the physics of falling sand, with obstacles, in real time. Each sand particule is a object that act like a *game of life* one at refresh.

**It is coded in C++**, and uses the SFML library.

## Goals

The goal with this project is to :

- Make a real-time sand filler that the user can move with his mouse.
- Make a real-time obstacle maker, following the user's mouse (changing from one another with a stroke).
- Add a sand repartition function to make the sand interaction realistic.
- Add inertia to complexify the simulation and make it more realistic.

## Features implemented

Menu output (instructions are in french) :

``` txt
----------------------------------------------------------
             Sand Simulation by Arthur FERT               
----------------------------------------------------------
Utilisez la souris pour interagir avec le tableau :
Ajouter du sable avec un clic gauche.
Ajouter un obstacle avec un clic droit.
Appuyez sur 'd' (delete) pour effacer le tableau.
Appuyez sur 'g' pour activer/désactiver la gomme.
Appuyez sur 'v' pour activer/désactiver le vide.
Appuyez sur 'i' pour activer/désactiver l'inertie.
----------------------------------------------------------
Veuillez entrer la largeur du tableau : 
Veuillez entrer la hauteur du tableau : 
```

- Add sand with left click
- Add obstacles with right click
- Type 'd' to erase the simulation
- Type 'g' to activate/deactivate the single cell erasor
- Type 'v' to activate/deactivate the ground
- Type 'i' to activate/deactivate inertia

## Authors and Licence

This project is under the [MIT license](./LICENSE) and is exclusively coded by Arthur FERT.
