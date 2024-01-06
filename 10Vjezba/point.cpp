#include "point.h"
#include <fstream>
#include <algorithm>
#include <iterator>

std::istream& operator>>(std::istream& input, Point& point) {
    input >> point.x >> point.y;
    return input;
}
std::ostream& operator<<(std::ostream& output, const Point& point) {
    output << "X: " << point.x << ", Y: " << point.y;
    return output;
}

void citaj_tocke(const std::string& ime_datoteke) {
    auto udaljenost_od_ishodista = [](const Point& p) {
        return std::sqrt(p.x * p.x + p.y * p.y);
        };

    auto udaljenost_jednaka = [&udaljenost_od_ishodista](const Point& p, double dist) {
        return std::abs(udaljenost_od_ishodista(p) - dist) < 0.00001;
        };

    std::ifstream file(ime_datoteke);
    if (!file.is_open()) {
        std::cerr << "Greska pri otvaranju datoteke." << std::endl;
        return;
    }
    std::vector<Point> points;
    std::copy(std::istream_iterator<Point>(file), std::istream_iterator<Point>(), std::back_inserter(points));

    std::sort(points.begin(), points.end(), [&udaljenost_od_ishodista](const Point& a, const Point& b) {
        return udaljenost_od_ishodista(a) < udaljenost_od_ishodista(b);
        });

    double radius = 5.0;
    int zbroj_unutar_radijusa = std::count_if(points.begin(), points.end(), [&udaljenost_od_ishodista, radius](const Point& p) {
        return udaljenost_od_ishodista(p) <= radius;
        });

    double udaljenost = 3.0;
    Point zamjeni{ 10.0, 10.0 };
    std::replace_if(points.begin(), points.end(), [&udaljenost_jednaka, udaljenost](const Point& p) {
        return udaljenost_jednaka(p, udaljenost);
        }, zamjeni);

    std::reverse_copy(points.begin(), points.end(), std::ostream_iterator<Point>(std::cout, "\n"));

    std::cout << "Broj tocaka unutar kruga promjera " << radius << ": " << zbroj_unutar_radijusa << std::endl;

    file.close();
}
