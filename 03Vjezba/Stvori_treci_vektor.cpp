#include <iostream>
#include "funkcije_vektori.hpp"

#include <vector>

std::vector<int>stvori_treci_vektor(std::vector<int>& vektor1, std::vector<int>& vektor2)
{
	std::vector<int> vektor3;
	

	for (int i = 0; i < vektor1.size(); i++)
	{
		int pronaden_u_vektoru2 = 0;

		for (int j = 0; j < vektor2.size(); j++)
		{

			if (vektor1[i] == vektor2[j])
			{
				pronaden_u_vektoru2 = 1; 
				break;  
			}
			
		}
		if (!pronaden_u_vektoru2) 
		{
			vektor3.push_back(vektor1[i]);
		}
	}
	return vektor3;
}


int main2()
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

	std::vector<int> vektor3= stvori_treci_vektor(vektor1, vektor2);

	ispis_vektora(vektor3);

	return 0;
}