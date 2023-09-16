#include <iostream>
#include <stack>

int main() {
    std::stack<int> pilha;

    pilha.push(1);
    pilha.push(2);
    pilha.push(3);

    while (!pilha.empty()) {
        std::cout << pilha.top() << " ";
        pilha.pop();
    }

    return 0;
}
