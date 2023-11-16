#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Karta {  
public:        
	int broj;
	std::string zog;
	
	Karta(int br, std::string z) : broj(br), zog(z) {} 
};

class Deck {
public:
	std::vector<Karta> karte; 

	Deck() 
	{
		for (int br = 1; br <= 40; br++) 
		{
			karte.push_back(Karta(br, "kupe"));
			karte.push_back(Karta(br, "bate"));
			karte.push_back(Karta(br, "spade"));
			karte.push_back(Karta(br, "dinari"));
		}
	}
	void shuffle() {
		std::random_shuffle(karte.begin(), karte.end());
	}

	std::vector<Karta> podijela_karata(int broj_igraca) 
	{
		std::vector<Karta> ruka; 
		for (int i = 0; i < broj_igraca * 10; i++) 
		{
			ruka.push_back(karte.back()); 
			karte.pop_back(); 
		}
		return ruka; 
	}
};

class Igrac {
public:
	std::string ime; 
	std::vector<Karta> kombinacija; 
	int bodovi; 

	Igrac(std::string i) : ime(i), bodovi(0) {} 

	void izracunaj_bodove() {
		int broj_aseva = 0, broj_dvica = 0, broj_trica = 0;
		int bodovi_za_akuzu_kupe = 0;
		int bodovi_za_akuzu_spade = 0;
		int bodovi_za_akuzu_bate = 0;
		int bodovi_za_akuzu_dinari = 0;

		for (Karta& karta : kombinacija) 
		{                                
			if (karta.broj == 1) 
			{
				broj_aseva++;
			}
			else if (karta.broj == 2)
			{
				broj_dvica++;
			}
			else if (karta.broj == 3)
			{
				broj_trica++;
			}

			if (karta.broj >= 1 && karta.broj <= 3) 
			{
				if (karta.zog == "kupe")
				{
					bodovi_za_akuzu_kupe++;
				}
				else if (karta.zog == "spade")
				{
					bodovi_za_akuzu_spade++;
				}
				else if (karta.zog == "bate") 
				{
					bodovi_za_akuzu_bate++;
				}
				else if (karta.zog == "dinari") 
				{
					bodovi_za_akuzu_dinari++;
				}
			}
		}

		if (broj_aseva == 3 || broj_dvica == 3 || broj_trica == 3)
		{
			bodovi += 4;
		}

		if (bodovi_za_akuzu_bate == 3 || bodovi_za_akuzu_dinari == 3 || bodovi_za_akuzu_kupe == 3 || bodovi_za_akuzu_spade == 3)
		{
			bodovi += 3;
		}
	}
};

int main()
{
	int broj_igraca;
	std::cout << "Unesite broj igraca (2 ili 4): ";
	std::cin >> broj_igraca;

	while (broj_igraca != 2 && broj_igraca != 4)
	{
		std::cout << "Pogrešan unos. Molimo unesite broj igraca (2 ili 4): ";
		std::cin >> broj_igraca;
	}

	std::vector<Igrac> igraci; 

	for (int i = 0; i < broj_igraca; i++)
	{
		std::string ime;
		std::cout << "Unesite ime igraca: ";
		std::cin >> ime;
		igraci.push_back(Igrac(ime));
	}

	Deck deck;
	deck.shuffle();

	for (Igrac& igrac : igraci) 
	{
		igrac.kombinacija = deck.podijela_karata(broj_igraca); 
	}

	for (Igrac& igrac : igraci) 
	{
		std::cout << igrac.ime << " ima " << igrac.bodovi << " bodova iz akuze." << std::endl;
	}
}
