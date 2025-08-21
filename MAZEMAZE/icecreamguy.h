#pragma once
#include "Point.h"


class icecreamguy
{public:
    Point pos; //Position de joueur
    void Drawguy(Point B);
    void Deleteguy(Point B);
    void Move(Point dir);
    void Drawhurtguy(Point B);
    void Drawhappyguy(Point B);
};

