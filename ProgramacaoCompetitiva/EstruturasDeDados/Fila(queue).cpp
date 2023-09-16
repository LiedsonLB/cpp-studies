#include <iostream>
#include <queue>

int main() {
    std::queue<int> fila;

    fila.push(1);
    fila.push(2);
    fila.push(3);

    while (!fila.empty()) {
        std::cout << fila.front() << " ";
        fila.pop();
    }

    return 0;
}