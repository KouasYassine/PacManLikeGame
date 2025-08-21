#include "Point.h"
Point Point::operator+(Point B){return Point {i+B.i,j+B.j};}
bool Point::operator==(const Point& other) const {
    return (i == other.i) && (j == other.j);
}
