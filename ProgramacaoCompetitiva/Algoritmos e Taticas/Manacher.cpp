#include <iostream>
#include <string>
#include <vector>

std::string encontrarMaiorPalindromo(const std::string& texto) {
    std::string str = "#";
    for (char c : texto) {
        str += c;
        str += '#';
    }

    int n = str.length();
    std::vector<int> P(n, 0);
    int C = 0, R = 0;

    for (int i = 1; i < n - 1; i++) {
        int espelho = 2 * C - i;

        if (R > i) {
            P[i] = std::min(R - i, P[espelho]);
        }

        while (str[i + P[i] + 1] == str[i - P[i] - 1]) {
            P[i]++;
        }

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int startIndex = (centerIndex - maxLen) / 2;
    return texto.substr(startIndex, maxLen);
}

int main() {
    std::string texto = "babad";
    std::string maiorPalindromo = encontrarMaiorPalindromo(texto);

    std::cout << "Maior substring palindrômica: " << maiorPalindromo << std::endl;

    return 0;
}
