
#pragma once
#include "Point.h"
class File
{
public:
    int taille; //Taille de la file
    Point * Fi; //Tableau pour le stockage des points
    File(Point A); //Constructeur avec un point initial
    void ajouter(Point A);
    void enlever();
    bool Vide(); //Vérifie si la file est vide
};

