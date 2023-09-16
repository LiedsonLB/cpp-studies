#include <iostream>
#include <vector>

using namespace std;

vector<int> encontrarTroco(int troco, const vector<int>& moedas) {
    vector<int> resultado;
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
    vector<int> moedas = {25, 10, 5, 1};

    vector<int> resultado = encontrarTroco(troco, moedas);

    cout << "Troco para " << troco << " centavos: ";
    for (int moeda : resultado) {
        cout << moeda << " ";
    }
    cout << endl;

    return 0;
}
