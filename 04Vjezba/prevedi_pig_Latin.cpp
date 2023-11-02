#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

bool je_samoglasnik(char c) 
{
    std::string samoglasnik = "aeiouAEIOU";
    return samoglasnik.find(c) != std::string::npos;
}

std::string prevedi(const std::string& str) 
{
    std::string promijenjen_str = str; 

    for (size_t i = 0; i < str.length(); i++) 
    {
        if (isalpha(str[i])) 
        {
            if (je_samoglasnik(str[i]))
            {
                if (i == 0) 
                {
                    promijenjen_str = str + "hay";
                }
                else
                {
                    promijenjen_str = str.substr(i) + str.substr(0, i) + "ay"; 
                }
                break;
            }
        }
    }
    return promijenjen_str;
}

int main()
{
    std::vector<std::string> input_recenice; 

    input_recenice.push_back("Where are you");
    input_recenice.push_back("Do you have the time");
    input_recenice.push_back("What time is it");

    int numStrings = input_recenice.size(); 
  
    int randomIndex = rand() % numStrings;
    std::string randomString = input_recenice[randomIndex];
    std::string pigLatinString = ""; 
    std::string str;
    std::istringstream iss(randomString);
    while (iss >> str)  
    {
        if (!pigLatinString.empty())
        {
            pigLatinString += " "; 
        }
        pigLatinString += prevedi(str);
    }
    std::cout << "Random string: " << randomString << std::endl;
    std::cout << "Pig Latin transformacija: " << pigLatinString << std::endl;

    return 0;
}