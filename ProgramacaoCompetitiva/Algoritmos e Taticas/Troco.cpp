#include <iostream>
#include <vector>

std::vector<int> encontrarTroco(int troco, const std::vector<int>& moedas) {
    std::vector<int> resultado;
    int n = moedas.size();

    for (int i = n - 1; i >= 0; i--) {
        while (troco >= moedas[i]) {
            troco -= moedas[i];
            resultado.push_back(moedas[i]);
        }
    }

    return resultado;
}

int main() {
    int troco = 63;
    std::vector<int> moedas = {25, 10, 5, 1};

    std::vector<int> resultado = encontrarTroco(troco, moedas);

    std::cout << "Troco para " << troco << " centavos: ";
    for (int moeda : resultado) {
        std::cout << moeda << " ";
    }
    std::cout << std::endl;

    return 0;
}
