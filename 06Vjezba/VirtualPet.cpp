#include "VirtualPet.h"

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

int VirtualPet::getHappiness() const {
    return bodovi_za_srecu;
}
