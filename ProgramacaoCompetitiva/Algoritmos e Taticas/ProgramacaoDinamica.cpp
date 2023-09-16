// Problema da Mochila (Knapsack) em DP

#include <iostream>
#include <vector>

int mochila(int capacidade, const std::vector<int>& pesos, const std::vector<int>& valores) {
    int n = pesos.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacidade + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacidade; w++) {
            if (pesos[i - 1] <= w) {
                dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - pesos[i - 1]] + valores[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacidade];
}

int main() {
    int capacidade = 10;
    std::vector<int> pesos = {2, 3, 4, 5};
    std::vector<int> valores = {3, 4, 5, 6};

    int resultado = mochila(capacidade, pesos, valores);

    std::cout << "Valor máximo que pode ser colocado na mochila: " << resultado << std::endl;

    return 0;
}

// Problema da Subsequência Comum Mais Longa (LCS) em DP

#include <iostream>
#include <vector>
#include <algorithm>

std::string lcs(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int length = dp[m][n];
    std::string resultado(length, ' ');

    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            resultado[--length] = str1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return resultado;
}

int main() {
    std::string str1 = "ABCD";
    std::string str2 = "ACDF";

    std::string resultado = lcs(str1, str2);

    std::cout << "A Subsequência Comum Mais Longa é: " << resultado << std::endl;

    return 0;
}
