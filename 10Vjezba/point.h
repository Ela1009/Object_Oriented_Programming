#ifndef POINT_H
#define POINT_H

#include <cmath>
#include <vector>
#include <iostream>

struct Point {
    double x;
    double y;
};

std::istream& operator>>(std::istream& input, Point& point);
std::ostream& operator<<(std::ostream& output, const Point& point);
void citaj_tocke(const std::string& ime_datoteke);

#endif // POINT_H
