#include <iostream>
#include <vector>
#include <stack>

class Grafo {
public:
    Grafo(int vertices);
    void adicionarAresta(int origem, int destino);
    void encontrarSCC();

private:
    int V;
    std::vector<std::vector<int>> adj;
    std::vector<int> low, disc;
    std::vector<bool> presenteStack;
    std::stack<int> pilha;
    int tempo;

    void SCCUtil(int u, std::vector<std::vector<int>>& SCC);
};

Grafo::Grafo(int vertices) : V(vertices) {
    adj.resize(V);
    tempo = 0;
    low.resize(V, -1);
    disc.resize(V, -1);
    presenteStack.resize(V, false);
}

void Grafo::adicionarAresta(int origem, int destino) {
    adj[origem].push_back(destino);
}

void Grafo::SCCUtil(int u, std::vector<std::vector<int>>& SCC) {
    disc[u] = low[u] = ++tempo;
    pilha.push(u);
    presenteStack[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            SCCUtil(v, SCC);
            low[u] = std::min(low[u], low[v]);
        } else if (presenteStack[v]) {
            low[u] = std::min(low[u], disc[v]);
        }
    }

    if (low[u] == disc[u]) {
        std::vector<int> componente;
        while (true) {
            int v = pilha.top();
            pilha.pop();
            presenteStack[v] = false;
            componente.push_back(v);
            if (v == u) {
                break;
            }
        }
        SCC.push_back(componente);
    }
}

void Grafo::encontrarSCC() {
    std::vector<std::vector<int>> SCC;
    
    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            SCCUtil(i, SCC);
        }
    }

    std::cout << "Componentes fortemente conexas:" << std::endl;
    for (std::vector<int> componente : SCC) {
        for (int v : componente) {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Grafo grafo(5);
    grafo.adicionarAresta(0, 1);
    grafo.adicionarAresta(1, 2);
    grafo.adicionarAresta(2, 0);
    grafo.adicionarAresta(1, 3);
    grafo.adicionarAresta(3, 4);

    grafo.encontrarSCC();

    return 0;
}