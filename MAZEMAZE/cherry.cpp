#include "cherry.h"
#include "Point.h"
#include <string>
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


cherry::cherry(Point B)
{cherry_pos.i=B.i; //set the line of the initial position
    cherry_pos.j=B.j; //set the column of the initial position
}
void cherry::Drawcherry(Point B){
    const int N=30;
    std::vector<std::string> cherrySprite = {
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000111111111100000000000",
        "000000000001111110000000000000",
        "000000000001100110000000000000",
        "000000000110000011000000000000",
        "000000011000000001100000000000",
        "000000110000000000110000000000",
        "000222222000000000222222000000",
        "002222222200000002222222200000",
        "022222222220000022222220020000",
        "022222222220000022222200220000",
        "002222222200000002222202200000",
        "000022220000000000022220000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000"
    };

    //Allocation dynamique d'un bloc contigu de N*N entiers
    int* grid = new int[N * N];
    Color col;

    //Parcours du sprite pour le dessiner
    for(int y = 0; y < N;y++) {
        for(int x = 0; x < N;x++) {
            char c = cherrySprite[y][x];
            grid[y * N + x] = (c == '1' ? 1 : 0); //stocke dans la grille
            //déterminaison de la couleur selon le caractère
            switch (c) {
            case '0': col = WHITE; break;
            case '1': col = GREEN; break;
            case '2': col = RED; break;
            case '3': col = Color(165,42,42); break;
            case '4': col = BLUE; break;
            default:  col = Color(100,100,100); break;
            }
            drawPoint(x+30*B.j,y+30*B.i,col); //dessine le pixel à la position
        }
    }

}

