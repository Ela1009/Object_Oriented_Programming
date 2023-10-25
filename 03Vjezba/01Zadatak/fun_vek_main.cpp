#include <iostream>
#include "funkcije_vektori.hpp"

int main()
{
	std::vector<int> vektor1;
	int n = 3;
	unos_vektora(vektor1, n);
	ispis_vektora(vektor1);

	std::vector<int> vektor2;
	int donja_granica = 3;
	int gornja_granica = 7;
	unos_vektora2(vektor2, donja_granica, gornja_granica);
	ispis_vektora(vektor2);
	return 0;
}