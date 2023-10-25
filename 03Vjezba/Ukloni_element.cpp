#include <iostream>
#include <vector>

std::vector<int>ukloni_vektor(std::vector<int>& vektor, int element)
{
	std::vector<int> vektor2;

	for (int i = 0; i < vektor.size(); i++)
	{
		if (vektor[i] != element)
		{
			vektor2.push_back(vektor[i]);
		}
	}
	return vektor2;
}

int main8()
{
	std::vector<int> vektor = { 1,2,3,4,5 };
	int element = 4;

	vektor=ukloni_vektor(vektor, element);

	for (int element : vektor)
	{
		std::cout << element << " ";
	}
	return 0;
}