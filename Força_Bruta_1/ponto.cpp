#include <cfloat>
#include <iostream>
#include <cmath>
#include <chrono>

/*

 A distância d(c1,c2) entre 2 coordenadas c1, formada pelo par (x1, y1) e c2, formada pelo par (x2, y2) pode ser calculada através da fórmula:
                                                d(c1,c2) =√(x1 − x2)^2 + (y1 − y2)^2.

 Descreva um algoritmo de força bruta que identifique as 2 (duas) coordenadas mais próximas num plano cartesiano.

*/

void cordprox(const int m[][2], int casos)
{
    int pontos[2][2];
    double menor = DBL_MAX;

    for (int i = 0; i < casos-1; i++)
    {

        for (int j = i+1; j < casos; j++)
        {
            int x1_x2 = m[i][0] - m[j][0];
            int y1_x2 = m[i][1] - m[j][1];
            double cord = std::sqrt(std::pow(x1_x2, 2) + std::pow(y1_x2, 2));
            if (cord < menor)
            {
                menor = cord;
                pontos[0][0] = m[i][0];
                pontos[0][1] = m[i][1];
                pontos[1][0] = m[j][0];
                pontos[1][1] = m[j][1];
            }
        }
    }

    std::cout << menor << " x1, y1 = " << pontos[0][0] <<", " << pontos[0][1]
    << " x2, y2 = "<< pontos[1][0] <<", " << pontos[1][1] << std::endl;
}

int main()
{
    int casos; std::cin>>casos;
    int cord[casos][2];
    for (int i = 0; i < casos; i++)
    {
        for (int j = 0; j <2; j++) std::cin>>cord[i][j];

    }

    auto beg = std::chrono::high_resolution_clock::now();
    cordprox(cord, casos);
    auto end = std::chrono::high_resolution_clock::now();

    auto dur = end - beg;
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(dur);
    std::cerr << casos << " Processing time: "<< duration.count() << " microseconds(s)" << std::endl;

    return 0;
}

