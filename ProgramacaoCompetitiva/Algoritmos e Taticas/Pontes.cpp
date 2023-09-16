#include <iostream>
#include <vector>

class Grafo {
public:
    Grafo(int vertices);
    void adicionarAresta(int origem, int destino);
    void encontrarPontes();

private:
    int V;
    std::vector<std::vector<int>> adj;
    int tempo;
    std::vector<int> disc, low;
    std::vector<std::pair<int, int>> pontes;

    void encontrarPontesUtil(int u, int pai);
};

Grafo::Grafo(int vertices) : V(vertices) {
    adj.resize(V);
    tempo = 0;
    disc.resize(V, -1);
    low.resize(V, -1);
}

void Grafo::adicionarAresta(int origem, int destino) {
    adj[origem].push_back(destino);
    adj[destino].push_back(origem);
}

void Grafo::encontrarPontesUtil(int u, int pai) {
    disc[u] = low[u] = tempo++;
    for (int v : adj[u]) {
        if (v == pai) continue;
        if (disc[v] == -1) {
            encontrarPontesUtil(v, u);
            low[u] = std::min(low[u], low[v]);
            if (low[v] > disc[u]) {
                pontes.push_back(std::make_pair(u, v));
            }
        } else {
            low[u] = std::min(low[u], disc[v]);
        }
    }
}

void Grafo::encontrarPontes() {
    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            encontrarPontesUtil(i, -1);
        }
    }

    std::cout << "Pontes no grafo:" << std::endl;
    for (auto& ponte : pontes) {
        std::cout << ponte.first << " - " << ponte.second << std::endl;
    }
}

int main() {
    Grafo grafo(5);
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(0, 2);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(3, 4);

    grafo.encontrarPontes();

    return 0;
}