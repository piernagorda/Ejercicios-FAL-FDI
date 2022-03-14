#include <iostream>
#include <fstream>
#include <vector>

int resolver(std::vector<int> const& estimacionAgua, int integrantes, int ini, int fin) {
    if (ini == fin) {
        int diasRestantes = estimacionAgua.size() - 1 - ini;
        if (estimacionAgua[ini] > diasRestantes * integrantes) return -1;
        else return ini;
    }
    else {
        int m = (ini + fin - 1) / 2;
        int diasRestantes = estimacionAgua.size()-1 - m;
        if (estimacionAgua[m] > diasRestantes * integrantes) return resolver(estimacionAgua, integrantes, m + 1, fin);
        else return resolver(estimacionAgua, integrantes, ini, m);
    }
}

void resuelveCaso() {
    int numDias, integrantes;
    std::cin >> numDias >> integrantes;
    std::vector<int> estimacionAgua(numDias);
    for (int i = 0; i < numDias; ++i) std::cin >> estimacionAgua[i];
    if (numDias == 1) {
        if (estimacionAgua[0] < integrantes) std::cout << 0 << std::endl;
        else std::cout << "SIN RACIONAMIENTO" << std::endl;
    }
    else {
        int sol = resolver(estimacionAgua, integrantes, 0, numDias - 1);
        if (sol == -1) std::cout << "SIN RACIONAMIENTO" << std::endl;
        else std::cout << sol << std::endl;
    }
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    int n; std::cin >> n;
    for (int i = 0; i < n; ++i) resuelveCaso();
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
}