#pragma once
#include "labyrinthe.h"
#include <vector>
#include <fstream>
#include <Imagine/Graphics.h>
using namespace Imagine;
using namespace std;
const int maxLevels = 5;
enum GameState{
    MENU,
    PLAYING,
    LEVEL_SELECT,
    GAME_OVER,
    LEVEL_COMPLETE
};
//struct GameData{
//    const int maxLevels=5;
//    int currentLevel;
//    int score;
//    int lives;
//    bool gameCompleted;
//    static int getLevelSize(int level){return 30+level*5;}
//    static int getLevelDensity(int level){return min(40+level*5,80);}
void save();
void load();
void unlockNextLevel();
//};
void showMenu();
void MenuInput(GameState& currentState, int& currentLevel);
Labyrinth initLevel(int level);
void showLevelSelection(int& unlockedLevels);
void levelSelection(int& unlockedLevels, int& currentLevel, GameState& currentState);
void showLevelComplete(int level);
void showGameOver(int score);

