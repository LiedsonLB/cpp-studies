#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> mapa;

    mapa["Alice"] = 25;
    mapa["Bob"] = 30;
    mapa["Charlie"] = 22;

    std::cout << "A idade de Alice é: " << mapa["Alice"] << std::endl;

    return 0;
}
