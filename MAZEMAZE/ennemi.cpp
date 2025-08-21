#include"outils.h"
#include"ennemi.h"
#include "Point.h"
#include "icecreamguy.h"
#include <Imagine/Graphics.h>

using namespace Imagine;
using namespace std;

const int z=30; //taille d'une case
Point dir1[4] = {{0,-1},{-1,0},{0,1},{1,0}}; //direction possible (haut, gauche, bas ,droite)
void Ennemi::Drawenemy(Point B){
    const int N=30;
    std::vector<std::string> spriteTex = {
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000000000000000000000",
        "000000000000011000000000000000",
        "000000000000133100000000000000",
        "000000000001333310000000000000",
        "000000100013333331001000000000",
        "000000110111333311101100000000",
        "000001111111111111111110000000",
        "000001111111111111111110000000",
        "000011112222222222222114000000",
        "000011111222111112221111400000",
        "444411113333333333333311444440",
        "444411111113333333311111444440",
        "444411111111222221111114444440",
        "000000041122111112211400000000",
        "000000000422111112240000000000",
        "000000000004111111400000000000",
        "000000000411411114114000000000",
        "000000000411444444114000000000",
        "000000000444400004444000000000",
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

    // 2) Allocation dynamique d'un bloc contigu de N*N entiers
    int* grid = new int[N * N];
    Color col;

    // 3) Conversion des '0'/'1' du spriteTex en int dans grid[]
    for(int y = 0; y < N;y++) {
        for(int x = 0; x < N;x++) {
            char c = spriteTex[y][x];
            grid[y * N + x] = (c == '1' ? 1 : 0);
            switch (c) {
            case '0': col = WHITE; break;
            case '1': col = ORANGE; break;
            case '2': col = BLACK; break;
            case '3': col = YELLOW; break;
            case '4': col = RED; break;

            default:  col = Color(100,100,100); break;
            }
            drawPoint(x+z*B.j,y+z*B.i,col);
        }
    }


}
void Ennemi::Moveenemy(int* tab, int taille, icecreamguy I) {
    int distance_max = 8;
    int dx = abs(pos.i - I.pos.i);
    int dy = abs(pos.j - I.pos.j);

    // Si icecreamguy est proche
    if (dx + dy <= distance_max) {
        // On cherche la direction qui rapproche le plus de icecreamguy
        Point bestDir = {0, 0};
        int bestDist = dx + dy;

        for (int d = 0; d < 4; ++d) {
            Point direction = dir1[d];
            Point newPos = {pos.i + direction.i, pos.j + direction.j};

            // Vérification des limites
            if (newPos.i < 0 || newPos.i >= taille || newPos.j < 0 || newPos.j >= taille)
                continue;

            if (tab[newPos.i + taille * newPos.j] == -1 || tab[newPos.i + taille * newPos.j] == 2)
                continue;

            int newDist = abs(newPos.i - I.pos.i) + abs(newPos.j - I.pos.j);
            if (newDist < bestDist) {
                bestDist = newDist;
                bestDir = direction;
            }
        }

        Point target = pos + bestDir;

        if (target == I.pos) {
            I.Drawhurtguy(I.pos);
            drawString(300, 300, "An Enemy caught up to you ! GAME OVER!", RED, 12);
            return;
        }

        Deleteenemy(pos);
        pos = target;
        Drawenemy(pos);
    } else {
        // Déplacement aléatoire comme avant
        for (int k = 0; k < 6; ++k) {
            int d = rand() % 4;
            Point direction = dir1[d];
            Point newPos = {pos.i + direction.i, pos.j + direction.j};

            if (newPos.i < 0 || newPos.i >= taille || newPos.j < 0 || newPos.j >= taille || tab[newPos.i + taille * newPos.j] == -1 || tab[newPos.i + taille * newPos.j] == 2)
                continue;

            if (newPos == I.pos) {
                I.Drawhurtguy(I.pos);
                drawString(300, 300, "An Enemy caught up to you ! GAME OVER!", RED, 12);
                return;
            }

            Deleteenemy(pos);
            pos = newPos;
            Drawenemy(pos);
            break; // un seul mouvement
        }
    }
}
void Ennemi:: Deleteenemy(Point B) {
    for (int j=0;j<z;j++){
        for (int i=0;i<z;i++){
            drawPoint(i+z*B.j,j+z*B.i,WHITE);
        }
    }
}
