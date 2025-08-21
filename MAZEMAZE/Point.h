#pragma once


class Point {
public:
    int i;
    int j;
    Point operator+(Point B);
    bool operator==(const Point& other) const;

};


