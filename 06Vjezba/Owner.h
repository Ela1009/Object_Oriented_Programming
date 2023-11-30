#ifndef OWNER_H
#define OWNER_H

#include <string>
#include <vector>
#include "VirtualPet.h"

class Owner {
    std::string ime_vlasnika;
    std::vector<VirtualPet> ljubimci;

public:
    Owner(std::string ime_vlasnika);

    void dodaj_ljubimca(std::string ime, std::string vrsta);
    void promijesaj_ljubimce();
    void igraj_se_sa_ljubimcima();
    void nahrani_ljubimce();
    int izracunaj_ukupnu_srecu() const;
    std::string get_ime_vlasnika() const;
};

#endif // OWNER_H