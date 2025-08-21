# pragma once
#include "Point.h"

class cherry
{
public:
    Point cherry_pos; //cherry's position in the grid
    cherry(); //default constructor
    cherry(Point B); //constructor with initial position
    void Drawcherry(Point B);
};

