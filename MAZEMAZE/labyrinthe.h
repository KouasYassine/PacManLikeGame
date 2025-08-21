#pragma once
#include <cstring>
#include <Imagine/Graphics.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>
#include <cassert>
#include "Point.h"
#include "File.h"
#include "icecreamguy.h"
#include "ennemi.h"
const int z=30; //Taille d'une case
class Labyrinth {
public:
    int taille; //Taille du labyrinthe (côté)
    int density; //Densité des murs (0-100)
    int * tab ; //Grille du labyrinthe (0=libre, -1=mur)
    int * c; //Tableau pour le chemin (utilisé dans PlusCourtchemin)
    bool * deja_vu; //Tableau pour marquer les cases visitées
    Point cible; //Position de l'arrivée
    Point depart; //Position de départ
    File F=File(depart);
    bool * occupied; //Cases occupées par des entités
    void destructor();
    Point Plusprochelibre(Point P); //Trouve la case libre la plus proche
    bool PlusCourtchemin(Point P,Point B); //Calcule le plus court chemin (BFS)
    bool affiche(); //Affiche le labyrinthe
    void affichechemin(); //Affiche le chemin trouvé
    void obscure ();
    Point findfreepos(bool * occupied); //Trouve une position libre aléatoire
    bool isCompleted(const Point& playerPos) const{return playerPos.i==cible.i && playerPos.j==cible.j;}
    void clear();
};
Labyrinth constructor ( int taille , int density, Point cible ,Point Dep);
