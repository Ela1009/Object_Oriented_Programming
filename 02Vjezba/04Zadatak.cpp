#include <iostream>
#include <iomanip>

struct matrica {
    int retci;
    int stupci;
    float** elementi; 
};

matrica* stvori_matricu(int m, int n)  
{
    matrica* matrix = new matrica; 
    matrix->retci = m; 
    matrix->stupci = n;
    matrix->elementi = new float* [m]; 
    for (int i = 0; i < m; ++i) { 
        matrix->elementi[i] = new float[n]; 
        for (int j = 0; j < n; ++j) { 
            matrix->elementi[i][j] = 0.0;
        }
    }
    return matrix; 
}

void unos_matrice(matrica* matrix)
{
    for (int i = 0; i < matrix->retci; ++i)
    {
        for (int j = 0; j < matrix->stupci; ++j)
        {
            std::cout << "Unesite vrijednost za element u retku " << i + 1 << " i stupcu " << j + 1 << ": ";
            std::cin >> matrix->elementi[i][j];
        }
    }
}

void generiraj_matricu(matrica* matrix, float a, float b) 
{
    for (int i = 0; i < matrix->retci; ++i) 
    {
        for (int j = 0; j < matrix->stupci; ++j)
        {
            matrix->elementi[i][j] = a + static_cast<float>(rand()) / RAND_MAX * (b - a); 
        }                                                                           
    }
}

matrica* zbroji_matrice(matrica* matrix1, matrica* matrix2)
{
    if (matrix1->retci != matrix2->retci || matrix1->stupci != matrix2->stupci)
    {
        std::cerr << "Mogu se zbrajati samo matrice istih dimenzija." << std::endl;
        return 0;
    }
    matrica* zbroj = stvori_matricu(matrix1->retci, matrix1->stupci);

    for (int i = 0; i < matrix1->retci; i++) 
    {
        for (int j = 0; j < matrix1->stupci; j++) 
        {
            zbroj->elementi[i][j] = matrix1->elementi[i][j] + matrix2->elementi[i][j]; 
        }
    }
    return zbroj;
}

matrica* oduzmi_matrice(matrica* matrix1, matrica* matrix2)
{
    if (matrix1->retci != matrix2->retci || matrix1->stupci != matrix2->stupci)
    {
        std::cerr << "Mogu se oduzimati samo matrice istih dimenzija." << std::endl;
        return 0;
    }

    matrica* rezultat = stvori_matricu(matrix1->retci, matrix1->stupci);

    for (int i = 0; i < matrix1->retci; i++)
    {
        for (int j = 0; j < matrix1->stupci; j++)
        {
            rezultat->elementi[i][j] = matrix1->elementi[i][j] - matrix2->elementi[i][j];
        }
    }
    return rezultat;
}

matrica* pomnozi_matrice(matrica* matrix1, matrica* matrix2)
{
    if (matrix1->stupci != matrix2->retci)
    {
        std::cerr << " Broj stupaca lijeve matrice nije jednak broju redaka desne matrice." << std::endl;
        return 0;
    }

    matrica* umnozak = stvori_matricu(matrix1->retci, matrix2->stupci);

    for (int i = 0; i < matrix1->retci; i++)
    {
        for (int j = 0; j < matrix2->stupci; j++)
        {
            for (int k = 0; k < matrix1->stupci; k++) 
            {
                umnozak->elementi[i][j] += matrix1->elementi[i][k] * matrix2->elementi[k][j]; 
            }                                                                                  
        }
    }
    return umnozak;
}

matrica* transponiraj_matricu(matrica* matrix)
{
    matrica* transponirana_matrica = stvori_matricu(matrix->stupci, matrix->retci);

    for (int i = 0; i < matrix->retci; i++)
    {
        for (int j = 0; j < matrix->stupci; j++)
        {
            transponirana_matrica->elementi[j][i] = matrix->elementi[i][j];
        }
    }
    return transponirana_matrica;
}

void ispisivanje_matrice(matrica* matrix) 
{
    for (int i = 0; i < matrix->retci; i++)
    {
        for (int j = 0; j < matrix->stupci; j++) 
        {
            std::cout << std::setprecision(4) << std::right << std::setw(10) << matrix->elementi[i][j]; 
        }                                                                         
        std::cout << std::endl;
    }
}

void izbrisi_matricu(matrica* matrix)
{
    for (int i = 0; i < matrix->retci; i++)
    {
        delete[] matrix->elementi[i];
    }
    delete[] matrix->elementi;
    delete matrix;
}

int main()
{
    int m, n; 

    std::cout << "Unesite broj redaka matrice: ";
    std::cin >> m;
    std::cout << "Unesite broj stupaca matrice: ";
    std::cin >> n;

    matrica* matrica1 = stvori_matricu(m, n); 

    std::cout << "Unos matrice 1:\n";
    unos_matrice(matrica1);

    std::cout << "Matrica 1:\n";
    ispisivanje_matrice(matrica1);

    matrica* matrica2 = stvori_matricu(m, n); 

    std::cout << "Generiranje matrice 2:\n";
    generiraj_matricu(matrica2, 1, 4);

    std::cout << "Matrica 2:\n";
    ispisivanje_matrice(matrica2);

    matrica* zbroj = zbroji_matrice(matrica1, matrica2);

    if (zbroj)
    {
        std::cout << "Zbroj matrice 1 i matrice 2:\n";
        ispisivanje_matrice(zbroj);
    }

    matrica* razlika = oduzmi_matrice(matrica1, matrica2);

    if (razlika)
    {
        std::cout << "Razlika matrice 1 i matrice 2:\n";
        ispisivanje_matrice(razlika);
    }

    int k; 
    std::cout << "Unesite broj stupaca za drugu matricu za mnozenje: ";
    std::cin >> k;

    matrica* matrica3 = stvori_matricu(n, k); 

    std::cout << "Generiranje matrice 3:\n";
    generiraj_matricu(matrica3, 1, 4);

    std::cout << "Matrica 3:\n";
    ispisivanje_matrice(matrica3);

    matrica* umnozak = pomnozi_matrice(matrica1, matrica3);

    if (umnozak)
    {
        std::cout << "Umnozak matrice 1 i matrice 3:\n";
        ispisivanje_matrice(umnozak);
    }

    matrica* transponirana = transponiraj_matricu(matrica1);

    if (transponirana)
    {
        std::cout << "Transponirana matrica 1:\n";
        ispisivanje_matrice(transponirana);
    }

    izbrisi_matricu(matrica1);
    izbrisi_matricu(matrica2);
    izbrisi_matricu(zbroj);
    izbrisi_matricu(razlika);
    izbrisi_matricu(matrica3);
    izbrisi_matricu(umnozak);
    izbrisi_matricu(transponirana);
}
