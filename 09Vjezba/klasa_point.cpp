#include <iostream>
#include <cmath>

template<typename T>
class point {
private:
    T x, y;

public:
    point(T x, T y) : x(x), y(y) {} 

    point operator-(const point& drugi) const { 
        T x_razlika = x - drugi.x;
        T y_razlika = y - drugi.y;
        return point(x_razlika, y_razlika);
    }

    friend double udaljenost(const point& p1, const point& p2) { 
        return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }

    friend std::ostream& operator<<(std::ostream& os, const point& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    point<int> p1(2, 3), p2(3, 4);
    std::cout << "Udaljenost tocaka " << p1 << " i " << p2 << " je " << udaljenost(p1, p2) << std::endl;
    return 0;
}