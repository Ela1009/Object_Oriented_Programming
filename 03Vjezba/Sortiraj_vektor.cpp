#include <iostream>
#include <vector>
#include <algorithm> 

int main5()
{
	std::vector<int> vektor = { 4,3,7,2,8 };

	std::sort(vektor.begin(), vektor.end());

	vektor.insert(vektor.begin(), 0);

	int suma = 0;

	for (int i = 0; i < vektor.size(); i++)
	{
		suma += vektor[i];
	}

	vektor.push_back(suma);

	for (int element : vektor)
	{
		std::cout << element << " ";
	}
	return 0;
}