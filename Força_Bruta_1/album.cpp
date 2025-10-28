#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

/*

 Clara está organizando as fotos da sua última viagem num álbum de fotos. Como ela tem muitas fotos, para
economizar páginas do álbum ela quer colar duas fotos por página do álbum.
Como as fotos são retangulares, as fotos podem ser coladas giradas (mas sempre com lados paralelos aos da página
do álbum, para preservar o equilíbrio estético do álbum), mas elas devem sempre ficar inteiramente contidas no
interior da página, e não devem se sobrepor.
Em geral, das muitas formas de posicionar as fotos do álbum só algumas (ou nenhuma) satisfazem estas restrições,
então pode ser difícil decidir se é possível colar as duas fotos em uma mesma página do álbum, e por isso Clara
pediu a sua ajuda para escrever um programa que, dadas as dimensões da página e das fotos, decide se é possível
colar as fotos na página.

 A primeira linha da entrada contém dois inteiros X e Y (1 ≤ X, Y ≤ 1000), indicando a largura e a altura da
página do álbum. Cada uma das duas linhas seguintes contém dois inteiros L e H (1 ≤ L, H ≤ 1000), indicando a
largura e a altura das fotos.
O programa deve imprimir uma única linha, contendo um único caractere: ’S’, se é possível colar as duas fotos na
página do álbum, e ’N’, caso contrário.

*/

using namespace std;

char existe(auto& array, int x) {
    int t = array.size();
    for (int i=0; i<t-1; i++) {
        if (array[i]>x) continue;
        for (int j = i+1; j<t; j++) {
            if ((array[i]+array[j])==x) return 'S';
        }
    }

    return 'N';
}


int main() {
    
    vector<int> v; 
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int aux; cin >> aux;
        v.push_back(aux);
    }
    int x; cin >> x;

    auto begin = std::chrono::high_resolution_clock::now();
    cout << existe(v, x) << endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
    std::cout << dur.count() << " microseconds" << endl;
    return 0;
}

