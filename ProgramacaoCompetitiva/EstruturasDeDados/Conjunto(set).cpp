#include <iostream>
#include <set>

int main() {
    std::set<int> conjunto;

    conjunto.insert(2);
    conjunto.insert(1);
    conjunto.insert(3);

    if (conjunto.find(2) != conjunto.end()) {
        std::cout << "O elemento 2 está no conjunto." << std::endl;
    }

    return 0;
}
