#include <iostream>
#include <vector>
#include <algorithm>

struct Aresta {
    int origem, destino, peso;
};

class Grafo {
public:
    Grafo(int V);
    void adicionarAresta(int origem, int destino, int peso);
    void kruskal();

private:
    int V;
    std::vector<Aresta> arestas;
};

Grafo::Grafo(int V) {
    this->V = V;
}

void Grafo::adicionarAresta(int origem, int destino, int peso) {
    Aresta aresta;
    aresta.origem = origem;
    aresta.destino = destino;
    aresta.peso = peso;
    arestas.push_back(aresta);
}

bool compararArestas(const Aresta& a, const Aresta& b) {
    return a.peso < b.peso;
}

void Grafo::kruskal() {
    std::vector<Aresta> arvore;
    std::sort(arestas.begin(), arestas.end(), compararArestas);

    std::vector<int> conjunto(V);
    for (int i = 0; i < V; i++) {
        conjunto[i] = i;
    }

    for (Aresta aresta : arestas) {
        int raizOrigem = conjunto[aresta.origem];
        int raizDestino = conjunto[aresta.destino];

        if (raizOrigem != raizDestino) {
            arvore.push_back(aresta);
            for (int i = 0; i < V; i++) {
                if (conjunto[i] == raizDestino) {
                    conjunto[i] = raizOrigem;
                }
            }
        }
    }

    std::cout << "Árvore Geradora Mínima (Kruskal):" << std::endl;
    for (Aresta aresta : arvore) {
        std::cout << "(" << aresta.origem << ", " << aresta.destino << ") - Peso: " << aresta.peso << std::endl;
    }
}

int main() {
    Grafo grafo(6);
    grafo.adicionarAresta(0, 1, 4);
    grafo.adicionarAresta(0, 2, 2);
    grafo.adicionarAresta(1, 2, 5);
    grafo.adicionarAresta(1, 3, 10);
    grafo.adicionarAresta(2, 3, 3);
    grafo.adicionarAresta(2, 4, 2);
    grafo.adicionarAresta(3, 4, 7);
    grafo.adicionarAresta(3, 5, 8);
    grafo.adicionarAresta(4, 5, 6);

    grafo.kruskal();

    return 0;
}
