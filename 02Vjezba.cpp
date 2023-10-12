#include <iostream>

void funkcija_pronadi_broj(int brojevi[], int n, int &najveci, int &najmanji)
{
	najveci = brojevi[0];
	najmanji = brojevi[0];

	for (int i = 0; i < n; i++)
	{
		if (brojevi[i] > najveci)
		{
			najveci = brojevi[i];
		}
		if (brojevi[i] < najmanji)
		{
			najmanji = brojevi[i];
		}
	}
}

int& funkcija_element_niza(int niz[], int indeks)
{
	return niz[indeks];
}



int main()
{
	/*int n = 5;
	int brojevi[5] = {1,2,3,4,5};
	int najveci, najmanji;
	funkcija_pronadi_broj(brojevi, n, najveci, najmanji);

	std::cout << "Najveci broj je: " << najveci << std::endl;
	std::cout << "Najmanji broj je: " << najmanji << std::endl;*/

	int niz[] = {1,2,3};
	int indeks = 2;

	funkcija_element_niza(niz, indeks)+=1;

	std::cout <<"Novi niz je: ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << niz[i] << " ";

	}
	std::cout << std::endl;

}