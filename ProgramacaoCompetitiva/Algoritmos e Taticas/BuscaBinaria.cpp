#include <iostream>
#include <vector>

using namespace std;

int buscaBinaria(const vector<int>& arr, int alvo) {
    int esquerda = 0;
    int direita = arr.size() - 1;

    while (esquerda <= direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        if (arr[meio] == alvo) {
            return meio; // Elemento encontrado
        } else if (arr[meio] < alvo) {
            esquerda = meio + 1; // Busca na metade direita
        } else {
            direita = meio - 1; // Busca na metade esquerda
        }
    }

    return -1; // Elemento não encontrado
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int alvo = 3;

    int resultado = buscaBinaria(arr, alvo);

    if (resultado != -1) {
        cout << "O elemento " << alvo << " está na posição " << resultado << endl;
    } else {
        cout << "O elemento " << alvo << " não foi encontrado no array." << endl;
    }

    return 0;
}
