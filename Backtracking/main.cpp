#include <iostream>
#include "Labirinto.h"
#include <vector>
#include <cstdlib>
#include <cstdio>

int main()
{
    std::string arquivo;
    std::cin >> arquivo;
    if (std::freopen(arquivo.c_str(), "r", stdin) == nullptr) return 1;
    std::vector<std::vector<int>> labirinto;
    int c, l, inicioC, inicioL, fimC, fimL;

    std::cin >> c >> l >> inicioC >> inicioL >> fimC >> fimL;

    labirinto.resize(l, std::vector<int>(c));

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            std::cin >> labirinto[i][j];
        }
    }

    system("cls");
    Labirinto novo;
    bool resultado = novo.resolverLab(labirinto, l, c, inicioC,inicioL, fimC, fimL);

    if (resultado) std::cout << "\n\nCaminho encontrado!";
    else std::cout << "\n\nCaminho inexistente!";
    return 0;
}