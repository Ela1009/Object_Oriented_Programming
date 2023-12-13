#ifndef VIRTUALPET_H
#define VIRTUALPET_H

#include <string>

class VirtualPet {
    std::string ime;
    std::string vrsta;
    int bodovi_za_glad;
    int bodovi_za_srecu;
    bool status_budnosti;
    static const int porcija = 20; 

public:
    VirtualPet(std::string ime, std::string vrsta);

    void spavaj();
    void jedi();
    void igraj_se();
    int get_sreca() const;

    bool operator==(const VirtualPet& drugi) const;
    bool operator!=(const VirtualPet& drugi) const;
    VirtualPet& operator=(const VirtualPet& drugi);
    VirtualPet& operator++();
    VirtualPet operator++(int);
    bool operator<(const VirtualPet& drugi) const;
    bool operator>(const VirtualPet& drugi) const;
    bool operator<=(const VirtualPet& drugi) const;
    bool operator>=(const VirtualPet& drugi) const;

    friend std::ostream& operator<<(std::ostream& out, const VirtualPet& pet);
};

#endif // VIRTUALPET_H
