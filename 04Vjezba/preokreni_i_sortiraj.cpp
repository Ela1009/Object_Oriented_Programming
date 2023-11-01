#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> preokreni_i_sortiraj(std::vector<std::string>& str, int broj_stringova) 
{
    std::string input; 
    std::cout << "Unesite " << broj_stringova << " stringa: " << std::endl;

    for (int i = 0; i < broj_stringova; i++)  
    {
        std::cin >> input; 
        std::reverse(input.begin(), input.end());
        str.push_back(input);
    }
    std::sort(str.begin(), str.end()); 

    return str; 
}

int main()
{
    int broj_stringova = 3;
    std::vector<std::string> str, obrnuti_i_sortirani_str; 
    obrnuti_i_sortirani_str = preokreni_i_sortiraj(str, broj_stringova);

    std::cout << "Obrnuti i sortirani stringovi: " << std::endl;
    for (const std::string& s : obrnuti_i_sortirani_str)
    {
        std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0;
}