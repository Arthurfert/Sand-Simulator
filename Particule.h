#pragma once

class Particule {
public:
    virtual ~Particule() = default; // Destructeur virtuel pour le polymorphisme

    // Méthode virtuelle pour mettre à jour la particule
    virtual void update(class Table& table, int x, int y, bool vide) = 0;
    virtual bool getM() const = 0; // Accesseur pour isMoving
};
