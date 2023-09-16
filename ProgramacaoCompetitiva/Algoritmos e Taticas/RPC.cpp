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

int BIT::consultar(int inicio, int fim) {
    return soma(fim) - soma(inicio - 1);
}

int main() {
    std::vector<int> sequencia = {1, 3, 2, 4, 6, 5, 8, 7};
    int tamanho = sequencia.size();

    BIT bit(tamanho);

    // Construir a BIT com os valores da sequência
    for (int i = 0; i < tamanho; i++) {
        bit.atualizar(i, sequencia[i]);
    }

    int consulta_inicio = 2;
    int consulta_fim = 5;

    int resposta = bit.consultar(consulta_inicio, consulta_fim);
    std::cout << "Resposta para consulta no intervalo [" << consulta_inicio << ", " << consulta_fim << "]: " << resposta << std::endl;

    return 0;
}