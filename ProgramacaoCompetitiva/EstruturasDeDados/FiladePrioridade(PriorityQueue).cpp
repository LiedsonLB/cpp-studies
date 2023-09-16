#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> fila_de_prioridade;

    fila_de_prioridade.push(3);
    fila_de_prioridade.push(1);
    fila_de_prioridade.push(2);

    while (!fila_de_prioridade.empty()) {
        std::cout << fila_de_prioridade.top() << " ";
        fila_de_prioridade.pop();
    }

    return 0;
}
