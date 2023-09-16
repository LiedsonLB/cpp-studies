#include <iostream>
#include <vector>
#include <string>

std::vector<int> calcularZFunction(const std::string& texto) {
    int n = texto.length();
    std::vector<int> Z(n, 0);

    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            Z[i] = std::min(Z[i - l], r - i + 1);
        }

        while (i + Z[i] < n && texto[Z[i]] == texto[i + Z[i]]) {
            Z[i]++;
        }

        if (i + Z[i] - 1 > r) {
            l = i;
            r = i + Z[i] - 1;
        }
    }

    return Z;
}

int main() {
    std::string texto = "abacabadabacaba";
    std::vector<int> Z = calcularZFunction(texto);

    std::cout << "Z-Function da string \"" << texto << "\": ";
    for (int z : Z) {
        std::cout << z << " ";
    }
    std::cout << std::endl;

    return 0;
}
