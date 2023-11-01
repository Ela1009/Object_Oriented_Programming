#include <iostream>
#include <string>

std::string ispravi_recenicu(std::string str, int duljina_stringa)
{
	for (int i = 0; i < duljina_stringa; i++)
	{
		if (ispunct(str[i + 1]) && isspace(str[i]))
		{
			str.erase(i, 1);
			duljina_stringa--;
		}
		if (ispunct(str[i]) && !isspace(str[i + 1]))
		{
			str.insert(i + 1, " ");
			duljina_stringa++;
		}
	}
	return str;
}

int main3()
{
	std::string str = "Ja bih ,ako ikako mogu , ovu recenicu napisala ispravno .";
	int duljina_stringa = str.length();

	str = ispravi_recenicu(str, duljina_stringa);

	std::cout << str << std::endl;

	return 0;
}