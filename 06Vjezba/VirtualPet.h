#ifndef VIRTUALPET_H
#define VIRTUALPET_H

#include <string>

class VirtualPet {
    std::string ime;
    std::string vrsta;
    int bodovi_za_glad;
    int bodovi_za_srecu;
    bool status_budnosti;

public:
    VirtualPet(std::string ime, std::string vrsta);

    void spavaj();
    void jedi();
    void igraj_se();
    int getHappiness() const;
};

#endif // VIRTUALPET_H

