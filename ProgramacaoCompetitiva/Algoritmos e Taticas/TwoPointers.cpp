// 1 - Encontrar um par de elementos em um array cuja soma seja igual a um valor alvo

#include <iostream>
#include <vector>
#include <algorithm>

bool encontrarParSoma(const std::vector<int>& nums, int alvo) {
    int esquerda = 0;
    int direita = nums.size() - 1;

    while (esquerda < direita) {
        int soma = nums[esquerda] + nums[direita];
        if (soma == alvo) {
            std::cout << "Par encontrado: " << nums[esquerda] << " e " << nums[direita] << std::endl;
            return true;
        } else if (soma < alvo) {
            esquerda++;
        } else {
            direita--;
        }
    }

    std::cout << "Par não encontrado." << std::endl;
    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    int alvo = 9;

    encontrarParSoma(nums, alvo);

    return 0;
}

// 2 - Encontrar a soma de três elementos em um array que seja igual a um valor alvo

#include <iostream>
#include <vector>
#include <algorithm>

bool encontrarTriplaSoma(const std::vector<int>& nums, int alvo) {
    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        int esquerda = i + 1;
        int direita = n - 1;

        while (esquerda < direita) {
            int soma = nums[i] + nums[esquerda] + nums[direita];
            if (soma == alvo) {
                std::cout << "Tripla encontrada: " << nums[i] << ", " << nums[esquerda] << ", " << nums[direita] << std::endl;
                return true;
            } else if (soma < alvo) {
                esquerda++;
            } else {
                direita--;
            }
        }
    }

    std::cout << "Tripla não encontrada." << std::endl;
    return false;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6};
    int alvo = 12;

    encontrarTriplaSoma(nums, alvo);

    return 0;
}
// 3 - Verificar se uma sequência é uma substring de outra sequência

#include <iostream>
#include <string>

bool verificarSubstring(const std::string& texto, const std::string& subtexto) {
    int m = texto.size();
    int n = subtexto.size();

    for (int i = 0; i <= m - n; i++) {
        int j = 0;
        while (j < n && texto[i + j] == subtexto[j]) {
            j++;
        }

        if (j == n) {
            return true;
        }
    }

    return false;
}

int main() {
    std::string texto = "Hello, World!";
    std::string subtexto = "World";

    if (verificarSubstring(texto, subtexto)) {
        std::cout << "O subtexto foi encontrado." << std::endl;
    } else {
        std::cout << "O subtexto não foi encontrado." << std::endl;
    }

    return 0;
}
