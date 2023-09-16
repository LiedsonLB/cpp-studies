#include <iostream>
#include <vector>

using namespace std;

vector<int> calcularSomaDePrefixos(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n, 0);

    prefixSum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefixSum = calcularSomaDePrefixos(arr);

    // Consulta de soma no intervalo [l, r]
    int l = 1, r = 3;
    int resultado = prefixSum[r] - (l > 0 ? prefixSum[l - 1] : 0);

    cout << "A soma no intervalo [" << l << ", " << r << "] é: " << resultado << endl;

    return 0;
}
