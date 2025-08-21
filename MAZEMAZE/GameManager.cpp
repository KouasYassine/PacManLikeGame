#include "GameManager.h"
#include "labyrinthe.h"
#include "outils.h"
#include <Imagine/Graphics.h>
using namespace Imagine;
using namespace std;
void showMenu(){
    fillRect(0,0,800,600,WHITE);
    drawString(300,100, "ICE CREAM MAZE", RED, 16);
    drawString(220,200,"Veuillez appuyer sur une touche", BLACK, 16);
    drawString(350,300,"1. Jouer", BLACK, 16);
    drawString(350,350, "2. Niveaux", BLACK, 16);
    drawString(350,400,"3. Quitter",BLACK, 16);
}
void MenuInput(GameState& currentState, int& currentLevel){
    int key=keyboard();
    switch(key){
    case '1':
        currentState=PLAYING;
        currentLevel=1;
        break;
    case '2':
        currentState=LEVEL_SELECT;
        break;
    case '3':
        exit(0);
    default:
        break;
    }
}
void showLevelSelection(int& unlockedLevels){
    fillRect(0,0,800,600,WHITE);
    drawString(250,100,"Sélection du niveau",BLACK,24,true);
    for(int i=0; i<maxLevels; i++){
        int y=200+i*50;
        drawString(350,y,"Niveau "+to_string(i+1),BLACK,16);

        if(i+1>unlockedLevels){
            drawString(450,y," - Vérrouillé",BLACK,16);
        }
    }
    drawString(200,500,"Appuyez sur M pour retourner au menu",BLACK,16);
}
void levelSelection(int& unlockedLevels, int& currentLevel, GameState& currentState){
    int key=keyboard();
    if(key>='1'&&key<='5'){
        int selected=key-'0';
        if(selected<=unlockedLevels){
            currentLevel=selected;
            currentState=PLAYING;
        }
    }
    else if(key=='m'||key=='M'){
        currentState=MENU;
    }
}
Labyrinth initLevel(int level){
    int size=30+level*10;
    int density=65-level*5;
    Point start={0,size/2};
    Point target={size-1,size/2};
    Labyrinth M;
    do{
        M=constructor(size,density,target,start);
    }while(!M.PlusCourtchemin(M.depart,M.cible));
    return M;
}
void showLevelComplete(int level){
    fillRect(0,0,800,600, Color(200,255,200));
    drawString(300,200, "NIVEAU "+to_string(level)+" REUSSI!", Color(0,100,0),24,true);
    drawString(300,300,"Score: "+to_string(level*500),BLACK,18);
    drawString(300,400, "Appuyez sur une touche", BLACK,16);
}
void showGameOver(int score){
    fillRect(0,0,800,600, Color(255,200,200));
    drawString(300,200,"GAME OVER",RED,24,true);
    drawString(300,300, "Score final: "+to_string(score),BLACK,18);
    drawString(300,400,"M : Menu principal",BLACK,18);
    drawString(300,450,"R : Recommencer", BLACK, 16);
}
