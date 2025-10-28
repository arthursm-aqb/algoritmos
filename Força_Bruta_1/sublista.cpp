#include <iostream>
#include <vector>
#include <chrono>

/*

 Considere um array A de n elementos. Exemplo: A = 10, 5, −17, 20, 50, −1, 3, −30, 10.
O problema consiste em encontrar a maior subsequencia consecutiva cuja soma seja a maior possível.
No caso do vetor A, a maior soma é 72, que é a soma dos elementos entre os índices 3 e 6: 20+50−1+3.
Não há soma maior do que esse de elementos consecutivos no vetor A. A soma deve possuir pelo menos um elemento, dessa forma não consideramos a soma nula.
A sublista deve possuir, pelo menos, um elemento.

 */
int slista(const auto& v, int tam)
{
    int maior = 0;

    for (int i = 0; i < tam; i++)
    {
        int aux = 0;
        for (int j = i; j<tam; j++)
        {
            int acum = v[i];

            for (int k = i+1; k < tam-aux; k++)
            {
                acum+=v[k];
            }

            aux++;
            if (acum > maior) maior = acum;
        }
    }

    return maior;
}


int main()
{
    std::vector<int> v; int tam ; std::cin >> tam;
    for (int i = 0; i < tam; i++)
    {
        int aux; std::cin >> aux;
        v.push_back(aux);
    }

    auto beg = std::chrono::high_resolution_clock::now();
    int res = slista(v, tam);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << res << std::endl;

    auto dur = end - beg;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(dur);
    std::cerr << tam << " Processing time: "<< duration.count() << " microseconds(s)" << std::endl;
    return 0;
}
