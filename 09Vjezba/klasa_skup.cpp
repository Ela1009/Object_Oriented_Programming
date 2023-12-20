#include <iostream>
#include <set>

template <typename T>
class Skup {
private:
    std::set<T> elementi; 

public:
    void dodaj_element(const T& element) {
        elementi.insert(element);
    }
    void izbaci_element(const T& element) {
        elementi.erase(element);
    }
    bool provjeri_element(const T& element) const {
        return elementi.find(element) != elementi.end();
    }
};

int main() {
    Skup<int> skup;

    skup.dodaj_element(1);
    skup.dodaj_element(2);
    skup.dodaj_element(3);
    skup.dodaj_element(4);
    skup.dodaj_element(5);

    if (skup.provjeri_element(1) == true)
    {
        std::cout << "1 je u skupu." << std::endl;
    }
    else
    {
        std::cout << "1 nije u skupu." << std::endl;
    }
    
    skup.izbaci_element(3);

    if (skup.provjeri_element(3) == true)
    {
        std::cout << "3 je u skupu." << std::endl;
    }
    else
    {
        std::cout << "3 nije u skupu." << std::endl;
    }

    return 0;
}
