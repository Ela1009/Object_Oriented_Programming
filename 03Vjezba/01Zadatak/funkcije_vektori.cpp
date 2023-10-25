#include "funkcije_vektori.hpp"
#include <iostream>

#include <vector>

std::vector<int>unos_vektora(std::vector<int>& vektor, int n)
{
	for (int i = 0; i < n; i++)
	{
		int element;
		std::cout << "Unesite elemente vektora: ";
		std::cin >> element;
		vektor.push_back(element);
	}
	std::cout << std::endl;
	return vektor;
}

std::vector<int>unos_vektora2(std::vector<int>& vektor2, int donja_granica, int gornja_granica)
{
	int element; 

	while (1)
	{
		std::cout << "Unesite elemente vektora: ";
		std::cin >> element;

		if (element<donja_granica || element>gornja_granica)
		{
			break;
		}
		vektor2.push_back(element);
	}
	std::cout << std::endl;
	return vektor2;
}

void ispis_vektora(std::vector<int>& v)
{
	std::cout << "Vektor: ";
	for (int num : v)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;
}