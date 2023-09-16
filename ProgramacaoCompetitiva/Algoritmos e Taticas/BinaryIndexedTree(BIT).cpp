#include <iostream>
#include <vector>

class BIT {
public:
    BIT(int size);
    void atualizar(int indice, int valor);
    int consultar(int indice);

private:
    std::vector<int> bit;
    int tamanho;

    int soma(int indice);
};

BIT::BIT(int size) {
    tamanho = size;
    bit.resize(size + 1, 0);
}

void BIT::atualizar(int indice, int valor) {
    indice++; // Ajuste para 1-based index
    while (indice <= tamanho) {
        bit[indice] += valor;
        indice += (indice & -indice);
    }
}

int BIT::soma(int indice) {
    int soma = 0;
    indice++; // Ajuste para 1-based index
    while (indice > 0) {
        soma += bit[indice];
        indice -= (indice & -indice);
    }
    return soma;
}

int BIT::consultar(int indice) {
    return soma(indice) - soma(indice - 1);
}

int main() {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8};
    int tamanho = array.size();

    BIT bit(tamanho);

    // Inicializar a BIT com os valores do array
    for (int i = 0; i < tamanho; i++) {
        bit.atualizar(i, array[i]);
    }

    std::cout << "Soma dos elementos de 0 a 4: " << bit.consultar(4) << std::endl;

    // Atualizar o valor do elemento no índice 2
    bit.atualizar(2, 10);

    std::cout << "Soma dos elementos de 0 a 4 após atualização: " << bit.consultar(4) << std::endl;

    return 0;
}
