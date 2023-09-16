#include <iostream>
#include <vector>

class SegTree {
public:
    SegTree(const std::vector<int>& array);
    int consulta(int inicio, int fim);
    void atualizar(int indice, int novoValor);

private:
    int tamanho;
    std::vector<int> segtree;

    void construir(const std::vector<int>& array, int no, int esquerda, int direita);
    int consultaIntervalo(int no, int esquerda, int direita, int inicio, int fim);
    void atualizarNo(int no, int esquerda, int direita, int indice, int novoValor);
};

SegTree::SegTree(const std::vector<int>& array) {
    tamanho = array.size();
    segtree.resize(4 * tamanho);
    construir(array, 1, 0, tamanho - 1);
}

void SegTree::construir(const std::vector<int>& array, int no, int esquerda, int direita) {
    if (esquerda == direita) {
        segtree[no] = array[esquerda];
        return;
    }

    int meio = (esquerda + direita) / 2;
    construir(array, 2 * no, esquerda, meio);
    construir(array, 2 * no + 1, meio + 1, direita);
    segtree[no] = segtree[2 * no] + segtree[2 * no + 1];
}

int SegTree::consultaIntervalo(int no, int esquerda, int direita, int inicio, int fim) {
    if (esquerda >= inicio && direita <= fim) {
        return segtree[no];
    }

    if (direita < inicio || esquerda > fim) {
        return 0;
    }

    int meio = (esquerda + direita) / 2;
    int esq = consultaIntervalo(2 * no, esquerda, meio, inicio, fim);
    int dir = consultaIntervalo(2 * no + 1, meio + 1, direita, inicio, fim);
    return esq + dir;
}

int SegTree::consulta(int inicio, int fim) {
    return consultaIntervalo(1, 0, tamanho - 1, inicio, fim);
}

void SegTree::atualizarNo(int no, int esquerda, int direita, int indice, int novoValor) {
    if (esquerda == direita) {
        segtree[no] = novoValor;
        return;
    }

    int meio = (esquerda + direita) / 2;
    if (indice <= meio) {
        atualizarNo(2 * no, esquerda, meio, indice, novoValor);
    } else {
        atualizarNo(2 * no + 1, meio + 1, direita, indice, novoValor);
    }

    segtree[no] = segtree[2 * no] + segtree[2 * no + 1];
}

void SegTree::atualizar(int indice, int novoValor) {
    atualizarNo(1, 0, tamanho - 1, indice, novoValor);
}

int main() {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8};
    int tamanho = array.size();

    SegTree segtree(array);

    std::cout << "Soma dos elementos de 0 a 4: " << segtree.consulta(0, 4) << std::endl;

    // Atualizar o valor do elemento no índice 2
    segtree.atualizar(2, 10);

