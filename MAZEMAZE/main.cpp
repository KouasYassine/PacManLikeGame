#include <Imagine/Graphics.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <iostream>
using namespace Imagine;
using namespace std;
#include "labyrinthe.h"
#include "outils.h"
#include "GameManager.h"

GameState currentState=MENU;
int currentLevel=1;
int unlockedLevels=1;
int main() {
     Window w=openWindow(800, 600);
    while(true) {
        switch(currentState) {
        case MENU:

            showMenu();
            MenuInput(currentState, currentLevel);

            break;
        case PLAYING: {
            Labyrinth M = initLevel(currentLevel);
            bool levelCompleted=M.affiche();
            if(levelCompleted){
                if(currentLevel==unlockedLevels && unlockedLevels<maxLevels){
                    unlockedLevels++;
                }
                currentLevel++;
                if(currentLevel > maxLevels) {
                    currentState = GAME_OVER;
                }
            }
            break;
        }
        case LEVEL_SELECT:
            showLevelSelection(unlockedLevels);
            levelSelection(unlockedLevels, currentLevel, currentState);
            break;
        case GAME_OVER:
            break;
        case LEVEL_COMPLETE:
            break;
        }
        milliSleep(50);
    }
    return 0;
}
