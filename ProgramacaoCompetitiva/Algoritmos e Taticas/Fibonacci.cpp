#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10; // Número de termos da série de Fibonacci a serem gerados

    std::cout << "Série de Fibonacci até o " << n << "º termo:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << fibonacci(i) << " ";
    }

    return 0;
}