#include <iostream>
#include "Food.h"
#include "VirtualPet.h"

int main() {
    Food food1; 
    Food food2; 

    Food::ispisi_counter(); 
    Food::promijeni_counter(5); 
    Food::ispisi_counter(); 
    std::cout << "Counter (non-member funkcija): " << get_counter() << std::endl;

    VirtualPet pet1("Ari", "pas"); 
    VirtualPet pet2("Cheesecake", "macka"); 

    std::cout << "Pet 1:\n" << pet1 << std::endl; 
    std::cout << "Pet 2:\n" << pet2 << std::endl; 
    
    pet1.jedi(); 
    pet2.spavaj(); 

    std::cout << "Ari nakon hranjenja:\n" << pet1 << std::endl;
    std::cout << "Cheesecake nakon spavanja:\n" << pet2 << std::endl;

    if (pet1 == pet2) {
        std::cout << "Ljubimci su jednaki." << std::endl;
    }
    else {
        std::cout << "Ljubimci nisu jednaki." << std::endl;
    }

    pet1++; 
    std::cout << "Ari nakon sto je pojeo jednu porciju:\n" << pet1 << std::endl;

    VirtualPet pet3 = pet2++; 
    std::cout << "Cheesecake nakon sto je pojeo porciju:\n" << pet2 << std::endl;
    std::cout << "Kopirao je treceg ljubimca:\n" << pet3 << std::endl;

    if (pet1 > pet2) {
        std::cout << "Ari je sretniji od Cheesecakea." << std::endl;
    }
    else {
        std::cout << "Cheesecake je sretniji od Arija." << std::endl;
    }

    return 0;
}
