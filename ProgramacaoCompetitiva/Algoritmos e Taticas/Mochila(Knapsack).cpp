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
