#pragma once
#include "Point.h"
#include "icecreamguy.h"

class Ennemi
{public:
    Point pos; //position actuelle de l'ennemi
    void Drawenemy(Point B);
    void Deleteenemy(Point B); //efface l'ennemi en position B
    void Moveenemy(int* tab, int taille, icecreamguy I);
};
