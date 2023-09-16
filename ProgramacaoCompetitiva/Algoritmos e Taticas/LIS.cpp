#include <iostream>
#include <vector>

int LIS(const std::vector<int>& sequencia) {
    int n = sequencia.size();
    std::vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequencia[i] > sequencia[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    int maiorLIS = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > maiorLIS) {
            maiorLIS = dp[i];
        }
    }

    return maiorLIS;
}

int main() {
    std::vector<int> sequencia = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int tamanho = sequencia.size();

    int resultado = LIS(sequencia);

    std::cout << "Tamanho da maior subsequência crescente: " << resultado << std::endl;

    return 0;
}
