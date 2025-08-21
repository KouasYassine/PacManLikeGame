#include "labyrinthe.h"
#include "outils.h"
#include <Imagine/Graphics.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>
#include <cassert>
#include "icecreamguy.h"
#include "ennemi.h"
#include "cherry.h"
using namespace Imagine;
using namespace std;


Labyrinth constructor ( int taille , int density,Point cible , Point Dep){
    Labyrinth L;
    L.tab = new int [taille*taille];
    L.c=new int [taille*taille];
    L.deja_vu=new bool [taille*taille];
    L.occupied=new bool [taille*taille];
    initRandom();
    //Vérification des paramètres
    assert( density >0 && density<=100);
    assert (cible.i <taille  && cible.j<taille && cible.i>=0 && cible.j>=0);
    //Initialisation des murs selon la densité
    int s [taille*taille];
    for (int k=0; k< density*taille*taille/100;k++){
        s[k]=0; //Cases libres
    }
    for (int k=density*taille*taille/100 ; k<taille*taille;k++){
        s[k]=-1; //Murs
    }
    //Mélange et affectation aléatoire
    for (int i=0; i<taille;i++){
        for (int j=0 ;j<taille;j++){
            int k=intRandom(0,taille*taille-1);
            L.tab[i+taille*j]=s[k];
            L.occupied[i+taille*j]=false;

        }
    }
    //Vérification de l'atteignabilité de la cible
    L.tab[cible.i+taille*cible.j]=0;
    //Initialisation des tableaux
    for (int i=0; i<taille*taille;i++){
        L.c[i]=-1;
        L.deja_vu[i]=false;
    }
    //Initialistion des propriétés
    L.taille=taille;
    L.density=density;
    L.cible=cible;
    L.depart=Dep;
    L.F=File(Dep);
    return L;
}
void Labyrinth::destructor(){
    delete [] tab ;
}

bool Labyrinth :: affiche (){ //Affichage du labyrinthe et des entités
    Window w=openWindow(taille*z ,taille*z);
    setActiveWindow(w);

    for (int i=0; i<taille;i++){
        for (int j=0 ;j<taille;j++){
            if ( tab [i+taille*j]==0){
                fillRect(z*j,z*i,z,z,WHITE);
            }
            if ( tab [i+taille*j]==-1){
                fillRect(z*j,z*i,z,z,BLACK);
            }


        }
    }



    //Initialisation des entités
    icecreamguy ice= icecreamguy();
    Ennemi E1=Ennemi();
    Ennemi E2=Ennemi();
    Ennemi E3=Ennemi();
    Ennemi E4=Ennemi();
    Ennemi E5=Ennemi();
    vector<Ennemi> enemies={E1,E2,E3,E4,E5};
    //Calcul et affichage du chemin
    //PlusCourtchemin(depart,cible);
    //affichechemin();
    //Positionnement initial des entités
    ice.pos=depart;
    E1.pos=cible;
    occupied[cible.i+taille*cible.j]=true;
    E2.pos=findfreepos(occupied);
    E3.pos=findfreepos(occupied);
    E4.pos=findfreepos(occupied);
    E5.pos=findfreepos(occupied);
    //Affichage des entités à leur position initiale

    ice.Drawguy(ice.pos);
    E1.Drawenemy(E1.pos);

    E2.Drawenemy(E2.pos);
    E3.Drawenemy(E3.pos);
    E4.Drawenemy(E4.pos);
    E5.Drawenemy(E5.pos);
    //Placement des cerises
    cherry C1=cherry(findfreepos(occupied));
    cherry C2=cherry(findfreepos(occupied));
    cherry C3=cherry(findfreepos(occupied));
    cherry C4=cherry(findfreepos(occupied));
    cherry C5=cherry(findfreepos(occupied));
    cherry C6=cherry(findfreepos(occupied));
    vector<cherry> cherries={C1,C2,C3,C4,C5,C6};
    //Boucle du jeu
    bool gameRunning = true;
    bool levelCompleted = false;
    int collected=0;
    tab[C1.cherry_pos.i+taille*C1.cherry_pos.j]=2;
    tab[C2.cherry_pos.i+taille*C2.cherry_pos.j]=2;
    tab[C3.cherry_pos.i+taille*C3.cherry_pos.j]=2;
    tab[C4.cherry_pos.i+taille*C4.cherry_pos.j]=2;
    tab[C5.cherry_pos.i+taille*C5.cherry_pos.j]=2;
    tab[C6.cherry_pos.i+taille*C6.cherry_pos.j]=2;
    clock_t lastMoveTime = clock();// Temps du dernier mouvement
    const int interval = 500;


    fillRect(z*cible.j,z*cible.i,z,z,RED);

    while (gameRunning && !levelCompleted) {


        clock_t now = clock();
        int elapsed = 1000.0 * (now - lastMoveTime) / CLOCKS_PER_SEC;
        // Dessin des cerises
        if (tab[C1.cherry_pos.i+taille*C1.cherry_pos.j]==2){
            C1.Drawcherry(C1.cherry_pos);}
        if (tab[C2.cherry_pos.i+taille*C2.cherry_pos.j]==2){
            C2.Drawcherry(C2.cherry_pos);}
        if (tab[C3.cherry_pos.i+taille*C3.cherry_pos.j]==2){
            C3.Drawcherry(C3.cherry_pos);}
        if (tab[C4.cherry_pos.i+taille*C4.cherry_pos.j]==2){
            C4.Drawcherry(C4.cherry_pos);}
        if (tab[C5.cherry_pos.i+taille*C5.cherry_pos.j]==2){
            C5.Drawcherry(C5.cherry_pos);}
        if (tab[C6.cherry_pos.i+taille*C6.cherry_pos.j]==2){
            C6.Drawcherry(C6.cherry_pos);}

        // Déplacement des ennemis
        if (elapsed >= interval) {
            // Déplacement des ennemis
            E1.Moveenemy(tab, taille, ice);
            fillRect(cible.j*z,cible.i*z,z,z,RED);
            E2.Moveenemy(tab, taille, ice);
            E3.Moveenemy(tab, taille, ice);
            E4.Moveenemy(tab, taille, ice);
            E5.Moveenemy(tab, taille, ice);


            lastMoveTime = now; // Mise à jour du dernier mouvement
        }





        // Gestion des entrées clavier
        bool Ok = true;
        while (Ok) {


            int s = keyboard();
            if (s != 0) {
                cout << "Touche pressée: " << s << endl;
                        Point f = ice.pos + dir[s-16777234];
                if (f.i >= 0 && f.i < taille && f.j >= 0 && f.j < taille) {
                    if (tab[f.i+taille*f.j] == 0||tab[f.i+taille*f.j] == 2) {
                        ice.Deleteguy(ice.pos);
                        ice.Move(dir[s-16777234]);
                        ice.Drawguy(ice.pos);



                        // Vérification des collisions avec les ennemis
                        if (ice.pos == E1.pos || ice.pos == E2.pos ||
                            ice.pos == E3.pos || ice.pos == E4.pos ||
                            ice.pos == E5.pos) {
                            ice.Drawhurtguy(ice.pos);

                            milliSleep(1000); // wait 1 second
                            closeWindow(w);
                            gameRunning = false;
                        }
                        if ((ice.pos == C1.cherry_pos || ice.pos == C2.cherry_pos  ||
                             ice.pos == C3.cherry_pos || ice.pos ==C4.cherry_pos ||
                             ice.pos == C5.cherry_pos||ice.pos==C6.cherry_pos) && tab[ice.pos.i+taille*ice.pos.j]==2){
                            fillRect(z*ice.pos.j,z*ice.pos.i,z,z,WHITE);
                            ice.Drawhappyguy(ice.pos);
                            collected++;
                            tab[ice.pos.i+taille*ice.pos.j]=0;
                        }
                        // Vérification si le joueur a atteint la cible
                        if (ice.pos.i == cible.i && ice.pos.j == cible.j && collected==5) {
                            ice.Drawhappyguy(ice.pos);
                            levelCompleted = true;
                        }
                    }

                }}
            else {
                Ok = false;
            }



        }


    }

    closeWindow(w);
    return levelCompleted;
}
Point Labyrinth::findfreepos(bool * occupied){
    initRandom();
    int x = rand()%taille;
    int y=rand()%taille;

    while (! (tab[x+taille*y]!=-1 && occupied[x+taille*y]==false && PlusCourtchemin(depart,Point{x,y})==true))
    {x=rand()%taille;
        y=rand()%taille;}
    occupied[x+taille*y]=true;
    return Point{x,y};



}
void Labyrinth::affichechemin(){
    if (deja_vu[cible.i+taille*cible.j]==true ){cout << "you have successfully reached your goal !"<<endl;
        int next_case=cible.i+taille*cible.j;
        //Remonte le chemin depuis la cible
        while (!(next_case==depart.i+depart.j *taille)){
            next_case=c[next_case];
            //Dessin du chemin en vert
            for (int i=0; i<taille;i++){
                for (int j=0 ;j<taille;j++){
                    if(  i+taille*j==next_case && deja_vu[i+taille*j]==true ){
                        fillRect(z*j,z*i,z,z,GREEN);
                    }
                }}

            std::cout <<next_case<<std::endl;
        }
    }
}
bool Labyrinth::PlusCourtchemin(Point P, Point B){
    if(tab[P.i+taille*P.j]==0){return false;}
    deja_vu[P.i+taille*P.j]=true;
    F=File(P);
    c[P.i+taille*P.j]=P.i+taille*P.j;
    while (deja_vu[B.i+taille*B.j]==false &&  F.Vide()==false){
        Point Sommet=F.Fi[0];
        deja_vu[Sommet.i+taille*Sommet.j]=true;
        int i= Sommet.i;
        int j=Sommet.j;
        int n=taille;
        if( i+1<n && tab[i+1+n*j]!=-1 && deja_vu[i+1+n*j]==false ){
            F.ajouter(Point{i+1,j});
            deja_vu[i+1+n*j]=true;
            c[i+1+n*j]=i+n*j;
        }

        if(i-1>=0 && tab[i-1+n*j]!=-1&& deja_vu[i-1+n*j]==false ){
            F.ajouter(Point{i-1,j});
            deja_vu[i-1+n*j]=true;
            c[i-1+n*j]=i+n*j;
        }
        if( j+1 <n && tab[i+n*(j+1)]!=-1 && deja_vu[i+n*(j+1)]==false ){
            F.ajouter(Point{i,j+1});
            deja_vu[i+n*(j+1)]=true;
            c[i+n*(j+1)]=i+n*j;
        }

        if( j-1 >=0 && tab[i+n*(j-1)]!=-1 && deja_vu[i+n*(j-1)]==false ){
            F.ajouter(Point{i,j-1});
            deja_vu[i+n*(j-1)]=true;
            c[i+n*(j-1)]=i+n*j;
        }
        F.enlever();


    }
    if (deja_vu[B.i+taille*B.j]==true){return true;}
    return false;
}
void Labyrinth::clear(){
    delete[] tab;
    delete[] c;
    delete[] deja_vu;
    delete[] occupied;
}

