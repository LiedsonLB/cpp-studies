#include <iostream>
#include <vector>
#include <queue>
#include <stack>

class Grafo {
public:
    Grafo(int numVertices);
    void adicionarAresta(int v1, int v2);
    void DFS(int vertice);
    void BFS(int vertice);

private:
    int numVertices;
    std::vector<std::vector<int>> listaAdj;
};

Grafo::Grafo(int numVertices) {
    this->numVertices = numVertices;
    listaAdj.resize(numVertices);
}

void Grafo::adicionarAresta(int v1, int v2) {
    listaAdj[v1].push_back(v2);
    listaAdj[v2].push_back(v1); // Em um grafo não direcionado, as arestas são bidirecionais
}

void Grafo::DFS(int vertice) {
    std::vector<bool> visitado(numVertices, false);

    std::stack<int> pilha;
    pilha.push(vertice);

    while (!pilha.empty()) {
        int v = pilha.top();
        pilha.pop();

        if (!visitado[v]) {
            visitado[v] = true;
            std::cout << v << " ";

            for (int vizinho : listaAdj[v]) {
                if (!visitado[vizinho]) {
                    pilha.push(vizinho);
                }
            }
        }
    }
}

void Grafo::BFS(int vertice) {
    std::vector<bool> visitado(numVertices, false);

    std::queue<int> fila;
    visitado[vertice] = true;
    fila.push(vertice);

    while (!fila.empty()) {
        int v = fila.front();
        fila.pop();
        std::cout << v << " ";

        for (int vizinho : listaAdj[v]) {
            if (!visitado[vizinho]) {
                visitado[vizinho] = true;
                fila.push(vizinho);
            }
        }
    }
}

int main() {
    Grafo grafo(6);
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(1, 4);
    grafo.adicionarAresta(2, 5);

    std::cout << "DFS a partir do vértice 0: ";
    grafo.DFS(0);
    std::cout << std::endl;

    std::cout << "BFS a partir do vértice 0: ";
    grafo.BFS(0);
    std::cout << std::endl;

    return 0;
}
