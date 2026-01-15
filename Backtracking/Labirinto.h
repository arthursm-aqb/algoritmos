#ifndef LABIRINTO_H
#define LABIRINTO_H

#include <iostream>
#include <ostream>
#include <vector>
#include <cstdlib>
#include <thread>
#include <chrono>


class Labirinto
{
    private:
        void setLab(const std::vector<std::vector<int>>& lab, int l, int c);
    public:
        bool resolverLab(std::vector<std::vector<int>>& lab, int l, int c, int linha, int coluna, int fLinha, int fColuna);
};

void Labirinto::setLab(const std::vector<std::vector<int>>& lab, int l, int c)
{
    std::cout << "\033[H";

    std::string buffer = "";

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (lab[i][j] == 1)
            {

                buffer += "\033[44m  \033[0m";
            }
            else if (lab[i][j] == 2)
            {

                buffer += "\033[1;32m. \033[0m";
            }
            else
            {

                buffer += "  ";
            }
        }

        buffer += "\n";
    }

    std::cout << buffer;

    std::this_thread::sleep_for(std::chrono::milliseconds(80));
}

bool Labirinto::resolverLab(std::vector<std::vector<int>>& lab, int l, int c, int linha, int coluna, int fLinha, int fColuna)
{
    if (linha<0 || coluna<0 || linha>=l || coluna>=c || lab[linha][coluna]!=0 || fLinha>=l || fColuna >=c || fLinha<0 || fColuna<0) return false;

    lab[linha][coluna] = 2;
    setLab(lab, l, c);

    if (fLinha==linha && fColuna==coluna)
    {
        return true;
    }

    if (resolverLab(lab, l, c, linha+1, coluna, fLinha, fColuna))
    {
        return true;
    }

    if (resolverLab(lab, l, c, linha, coluna+1, fLinha, fColuna))
    {
        return true;
    }

    if (resolverLab(lab, l, c, linha, coluna-1, fLinha, fColuna)) return true;

    if (resolverLab(lab, l, c, linha-1, coluna, fLinha, fColuna)) return true;

    lab[linha][coluna] = 0;
    setLab(lab, l, c);
    return false;
}


#endif