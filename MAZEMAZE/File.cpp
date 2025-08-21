#include "File.h"
#include <Imagine/Graphics.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>
#include <cassert>
using namespace Imagine;
using namespace std;

File::File(Point A){ //Initialisation de la file avec un premier point
    taille=1;
    Fi=new Point[taille];
    Fi[0]=A; //Premier élément
}
void File::ajouter(Point A){ //Ajout d'un élément en fin de file
    Point * F1=new Point[taille+1]; //Augmentation de la file
    for (int i=0; i<taille;i++){ //Recopie de la file précédente
        F1[i]=Fi[i];
    }
    F1[taille]=A; //Ajout de l'élément
    delete []Fi; //Libération de la mémoire allouée au précédent tableau
    Fi=F1;
    taille++;    
}
void File::enlever(){ //Suppresion du dernier élément de la file (même méthode que pour l'ajout)
    assert (taille >0);
    Point * F1=new Point[taille-1];
    for (int i=0; i<taille-1;i++){
        F1[i]=Fi[i+1];
    }
    delete []Fi;
    Fi=F1;
    taille=taille-1;
}
bool  File::Vide(){
    if (taille==0){cout << "file vide "<<endl;}
    return taille==0;}
