#include <iostream>
#include <vector>

class No {
public:
    int valor;
    No* esquerda;
    No* direita;

    No(int valor) : valor(valor), esquerda(nullptr), direita(nullptr) {}
};

class Arvore {
public:
    No* raiz;
    Arvore() : raiz(nullptr) {}
};

No* encontrarLCA(No* no, int valor1, int valor2) {
    if (no == nullptr) return nullptr;

    if (no->valor == valor1 || no->valor == valor2) {
        return no;
    }

    No* esquerdaLCA = encontrarLCA(no->esquerda, valor1, valor2);
    No* direitaLCA = encontrarLCA(no->direita, valor1, valor2);

    if (esquerdaLCA && direitaLCA) {
        return no;
    }

    return (esquerdaLCA != nullptr) ? esquerdaLCA : direitaLCA;
}

int main() {
    Arvore arvore;
    arvore.raiz = new No(3);
    arvore.raiz->esquerda = new No(5);
    arvore.raiz->direita = new No(1);
    arvore.raiz->esquerda->esquerda = new No(6);
    arvore.raiz->esquerda->direita = new No(2);
    arvore.raiz->direita->esquerda = new No(0);
    arvore.raiz->direita->direita = new No(8);
    arvore.raiz->esquerda->direita->esquerda = new No(7);
    arvore.raiz->esquerda->direita->direita = new No(4);

    int valor1 = 5;
    int valor2 = 1;

    No* lca = encontrarLCA(arvore.raiz, valor1, valor2);

    if (lca != nullptr) {
        std::cout << "O LCA de " << valor1 << " e " << valor2 << " é " << lca->valor << std::endl;
    } else {
        std::cout << "Um dos nós não foi encontrado na árvore." << std::endl;
    }

    return 0;
}
