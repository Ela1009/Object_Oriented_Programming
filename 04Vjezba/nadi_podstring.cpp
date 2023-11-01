#include <iostream>
#include <string>

int nadi_podstring(std::string& str, std::string& substr)
{
	int brojac = 0;
	size_t pos = 0; 
	
	while ((pos = str.find(substr, pos)) != std::string::npos)
	{
		brojac++;
		pos += substr.length(); 
	}
	return brojac;
}

int main2()
{
	std::string str = "ovo je string ovo";
	std::string substr = "ovo";

	int broj_javljanja = nadi_podstring(str, substr);

	std::cout << "Podstring se javlja " << broj_javljanja << " puta u stringu" << std::endl;

	return 0;
}