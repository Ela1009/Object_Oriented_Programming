#include <iostream>
#include <algorithm>

template <typename T>
void sortiraj_niz(T niz[], int len) { 
    std::sort(niz, niz + len); 
}

template <> 
void sortiraj_niz<char>(char niz[], int len) {
    std::sort(niz, niz + len, [](char a, char b) {
        return std::tolower(a) < std::tolower(b); 
        });
}

int main4() {
    int niz_int[] = { 2, 1, 4, 11, 5, 10 };
    char niz_char[] = { 'B', 'a', 'C' };

    int len_int = sizeof(niz_int) / sizeof(niz_int[0]);
    int len_char = sizeof(niz_char) / sizeof(niz_char[0]);

    sortiraj_niz(niz_int, len_int);
    sortiraj_niz(niz_char, len_char);

    for (int i = 0; i < len_int; i++) {
        std::cout << niz_int[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < len_char; i++) {
        std::cout << niz_char[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
