#include "VirtualPet.h"
#include <iostream>

VirtualPet::VirtualPet(std::string ime, std::string vrsta)
    : ime(ime), vrsta(vrsta), bodovi_za_glad(100), bodovi_za_srecu(100), status_budnosti(true) {}

void VirtualPet::spavaj() {
    bodovi_za_srecu += 20;
    bodovi_za_glad += 20;
}

void VirtualPet::jedi() {
    bodovi_za_srecu += 20;
    bodovi_za_glad -= 20;

    if (bodovi_za_glad <= 50) {
        status_budnosti = false;
        spavaj();
    }
}

void VirtualPet::igraj_se() {
    bodovi_za_srecu += 20;
    bodovi_za_glad += 20;
}

int VirtualPet::get_sreca() const {
    return bodovi_za_srecu;
}

bool VirtualPet::operator==(const VirtualPet& drugi) const {
    return (ime == drugi.ime && vrsta == drugi.vrsta &&
        bodovi_za_glad == drugi.bodovi_za_glad &&
        bodovi_za_srecu == drugi.bodovi_za_srecu &&
        status_budnosti == drugi.status_budnosti);
}

bool VirtualPet::operator!=(const VirtualPet& drugi) const {
    return !(*this == drugi);
}

VirtualPet& VirtualPet::operator=(const VirtualPet& drugi) {
    if (this != &drugi) {
        ime = drugi.ime;
        vrsta = drugi.vrsta;
        bodovi_za_glad = drugi.bodovi_za_glad;
        bodovi_za_srecu = drugi.bodovi_za_srecu;
        status_budnosti = drugi.status_budnosti;
    }
    return *this;
}

VirtualPet& VirtualPet::operator++() {
    bodovi_za_glad -= porcija; 
    return *this;
}

VirtualPet VirtualPet::operator++(int) {
    VirtualPet temp = *this;
    ++(*this); 
    return temp;
}

bool VirtualPet::operator<(const VirtualPet& drugi) const {
    return bodovi_za_srecu < drugi.bodovi_za_srecu;
}

bool VirtualPet::operator>(const VirtualPet& drugi) const {
    return bodovi_za_srecu > drugi.bodovi_za_srecu;
}

bool VirtualPet::operator<=(const VirtualPet& drugi) const {
    return bodovi_za_srecu <= drugi.bodovi_za_srecu;
}

bool VirtualPet::operator>=(const VirtualPet& drugi) const {
    return bodovi_za_srecu >= drugi.bodovi_za_srecu;
}

std::ostream& operator<<(std::ostream& out, const VirtualPet& pet) {
    out << "  Ime: " << pet.ime << std::endl;
    out << "  Vrsta: " << pet.vrsta << std::endl;
    out << "  Sreca: " << pet.bodovi_za_srecu << std::endl;
    out << "  Glad: " << pet.bodovi_za_glad << std::endl;
    out << "  Budan: ";
    if (pet.status_budnosti) {
        out << "Budan";
    }
    else {
        out << "Nije budan";
    }
    out << std::endl;
    return out;
}
