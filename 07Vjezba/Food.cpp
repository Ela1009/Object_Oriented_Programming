#include "Food.h"
#include <iostream>

int Food::counter = 0;

Food::Food() {
    counter++; 
}

Food::~Food() {
    counter--; 
}

void Food::promijeni_counter(int broj) {
    counter = broj;
}

void Food::ispisi_counter() {
    std::cout << "counter je: " << counter << std::endl;
}

int Food::get() {
    return counter;
}

int get_counter() {
    return Food::get();
}
