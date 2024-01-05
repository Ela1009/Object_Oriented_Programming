#include "words.h"

int main() {
    std::string ime_datoteke = "words.txt";
    std::string rijec_koju_trazimo = "trazi";
    std::string rijec_koju_uklanjamo = "ukloni";

    words(ime_datoteke, rijec_koju_trazimo, rijec_koju_uklanjamo);

    return 0;
}
