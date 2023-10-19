#include <iostream>

struct vector {
	int* elementi;
	int logicka_velicina;
	int fizicka_velicina;

	void vector_new(int init_velicina)
	{
		elementi = new int[init_velicina]; 
		logicka_velicina = 0; 
		fizicka_velicina = init_velicina; 
	}

	void vector_delete() 
	{
		delete[] elementi; 
	}

	void vector_push_back(int n) 
	{
		if (logicka_velicina == fizicka_velicina) 
		{										  
			int nova_fizicka_velicina;
			if (fizicka_velicina > 0)
			{ 
				nova_fizicka_velicina = fizicka_velicina * 2;
			}
			else
			{
				nova_fizicka_velicina = 1;
			}
			int* novi_elementi = new int[nova_fizicka_velicina]; 
		
			for (int i = 0; i < logicka_velicina; i++) 
			{ 
				novi_elementi[i] = elementi[i];
			}
			delete[] elementi; 
			elementi = novi_elementi; 
			fizicka_velicina = nova_fizicka_velicina; 
		}
		elementi[logicka_velicina++] = n; 
	}

	void vector_pop_back() 
	{
		logicka_velicina--;
	}

	int vector_front() 
	{
		return elementi[0];
	}

	int vector_back() 
	{
		return elementi[logicka_velicina - 1];
	}

	int vector_size()
	{
		return logicka_velicina;
	}
};

int main()
{
	vector Vektor_test;

	Vektor_test.vector_new(3); 
	Vektor_test.vector_push_back(1);
	Vektor_test.vector_push_back(2);
	Vektor_test.vector_push_back(3); 

	for (int i = 0; i < Vektor_test.vector_size(); i++)
	{
		std::cout << Vektor_test.elementi[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Prvi element je: " << Vektor_test.vector_front() << std::endl;

	std::cout << "Posljednji element je: " << Vektor_test.vector_back() << std::endl;

	std::cout << "Velicina je: " << Vektor_test.vector_size() << std::endl;

	Vektor_test.vector_pop_back();

	std::cout << "Nakon funkcije pop_back posljednji element je: " << Vektor_test.vector_back() << std::endl;

	Vektor_test.vector_delete();
}