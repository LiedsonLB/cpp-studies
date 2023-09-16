#include <iostream>
#include <string>

unsigned long hashString(const std::string& str) {
    unsigned long hash = 5381; // Valor inicial recomendado para o algoritmo djb2
    for (char c : str) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}

int main() {
    std::string texto = "Hello, World!";
    unsigned long hashValue = hashString(texto);

    std::cout << "String: " << texto << std::endl;
    std::cout << "Valor Hash: " << hashValue << std::endl;

    return 0;
}