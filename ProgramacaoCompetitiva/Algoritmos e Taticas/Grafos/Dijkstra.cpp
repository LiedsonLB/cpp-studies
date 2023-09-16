#include <iostream>
#include <vector>
#include <queue>
#include <climits>

const int INF = INT_MAX; // Valor que representa infinito

class Grafo {
public:
    Grafo(int numVertices);
    void adicionarAresta(int v1, int v2, int peso);
    void dijkstra(int origem);

private:
    int numVertices;
    std::vector<std::vector<std::pair<int, int>>> listaAdj; // Lista de adjacência (vértice de destino, peso da aresta)
};

Grafo::Grafo(int numVertices) {
    this->numVertices = numVertices;
    listaAdj.resize(numVertices);
}

void Grafo::adicionarAresta(int v1, int v2, int peso) {
    listaAdj[v1].push_back(std::make_pair(v2, peso));
    listaAdj[v2].push_back(std::make_pair(v1, peso)); // Em um grafo não direcionado, as arestas são bidirecionais
}

void Grafo::dijkstra(int origem) {
    std::vector<int> dist(numVertices, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> filaPrioridade;

    dist[origem] = 0;
    filaPrioridade.push(std::make_pair(0, origem));

    while (!filaPrioridade.empty()) {
        int u = filaPrioridade.top().second;
        filaPrioridade.pop();

        for (auto vizinho : listaAdj[u]) {
            int v = vizinho.first;
            int peso = vizinho.second;

            if (dist[v] > dist[u] + peso) {
                dist[v] = dist[u] + peso;
                filaPrioridade.push(std::make_pair(dist[v], v));
            }
        }
    }

    std::cout << "Menores distâncias a partir do vértice " << origem << ":\n";
    for (int i = 0; i < numVertices; i++) {
        std::cout << "Vértice " << i << ": " << dist[i] << std::endl;
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

    grafo.dijkstra(0);

    return 0;
}
