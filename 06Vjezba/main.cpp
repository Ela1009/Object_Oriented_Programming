#include "VirtualPet.h"
#include "Owner.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

int main() {
    Owner vlasnik1("Ana");
    Owner vlasnik2("Iva");
    Owner vlasnik3("Ivo");

    int broj_ljubimaca = 3;

    for (int i = 0; i < broj_ljubimaca; i++) {
        std::string pet_ime = "Pet";
        vlasnik1.dodaj_ljubimca(pet_ime, "Pas");
        vlasnik2.dodaj_ljubimca(pet_ime, "Macka");
        vlasnik3.dodaj_ljubimca(pet_ime, "Zec");
    }

    vlasnik1.igraj_se_sa_ljubimcima();
    vlasnik1.nahrani_ljubimce();

    vlasnik2.igraj_se_sa_ljubimcima();
    vlasnik2.nahrani_ljubimce();

    vlasnik3.igraj_se_sa_ljubimcima();
    vlasnik3.nahrani_ljubimce();

    std::vector<std::pair<Owner*, int>> sreca; 

    sreca.push_back(std::make_pair(&vlasnik1, vlasnik1.izracunaj_ukupnu_srecu()));
    sreca.push_back(std::make_pair(&vlasnik2, vlasnik2.izracunaj_ukupnu_srecu()));
    sreca.push_back(std::make_pair(&vlasnik3, vlasnik3.izracunaj_ukupnu_srecu()));

    std::sort(sreca.begin(), sreca.end(), [](const auto& a, const auto& b){
        return a.second > b.second;
        });

    std::cout << "Vlasnik najsretnijeg ljubimca je: " << sreca[0].first->get_ime_vlasnika() << std::endl;
   
    return 0;
}

