#include "Owner.h"
#include <iostream>
#include <random>
#include <algorithm>

Owner::Owner(std::string ime_vlasnika) : ime_vlasnika(ime_vlasnika) {} 

void Owner::dodaj_ljubimca(std::string ime, std::string vrsta)
{
    ljubimci.push_back(VirtualPet(ime, vrsta));
    std::cout << ime << " je postao ljubimac" << std::endl;
}

void Owner::promijesaj_ljubimce()
{
    std::random_shuffle(ljubimci.begin(), ljubimci.end());
}

void Owner::igraj_se_sa_ljubimcima()
{
    promijesaj_ljubimce();
    for (VirtualPet& pet : ljubimci)
    {
        pet.igraj_se();
    }
}

void Owner::nahrani_ljubimce()
{
    promijesaj_ljubimce();
    for (VirtualPet& pet : ljubimci)
    {
        pet.jedi();
    }
}

int Owner::izracunaj_ukupnu_srecu() const {
    int ukupna_sreca = 0;
    for (const VirtualPet& pet : ljubimci)
    {
        ukupna_sreca += pet.getHappiness();
        return ukupna_sreca;
    }
}

std::string Owner::get_ime_vlasnika() const {
    return ime_vlasnika;
}
