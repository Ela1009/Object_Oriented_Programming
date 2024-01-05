#include "words.h"
#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm>
#include <iterator> 

void words(const std::string& ime_datoteke, const std::string& rijec_koju_trazimo, const std::string& rijec_koju_uklanjamo) {

    std::ifstream file(ime_datoteke);
    if (!file.is_open()) {
        std::cout << "Greska u otvaranju datoteke." << std::endl;
        return;
    }
    std::vector<std::string> rijeci;
    std::copy(std::istream_iterator<std::string>(file), std::istream_iterator<std::string>(), std::back_inserter(rijeci));

    std::vector<int> pozicije;
    auto it = std::find(rijeci.begin(), rijeci.end(), rijec_koju_trazimo);
    while (it != rijeci.end()) {
        pozicije.push_back(std::distance(rijeci.begin(), it));
        it = std::find(it + 1, rijeci.end(), rijec_koju_trazimo);
    }

    rijeci.erase(std::remove_if(rijeci.begin(), rijeci.end(), [&](const std::string& str) {
        return str.find(rijec_koju_uklanjamo) != std::string::npos;
        }), rijeci.end());

    std::transform(rijeci.begin(), rijeci.end(), rijeci.begin(), [](std::string& str) {
        std::transform(str.begin(), str.end(), str.begin(), ::toupper);
        return str;
        });

    std::ostream_iterator<std::string> output(std::cout, "\n");
    std::copy(rijeci.begin(), rijeci.end(), output);

    file.close();
}
