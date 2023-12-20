#include <iostream>

template<typename T> 
T min(T a, T b)       
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main() {
    int a = 2;
    int b = 3;
    char c = 'a';
    char d = 'b';
    int prvi = min(a, b);
    char drugi = min(c, d);

    std::cout << prvi << std::endl;
    std::cout << drugi << std::endl;

    return 0;
}
