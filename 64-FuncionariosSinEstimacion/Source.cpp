#include <iostream>
#include <fstream>
#include <vector>

int MAX = 100000000;

void resolver(std::vector<std::vector<int>> tiempoTareas, int k, std::vector<bool> funcionariosOcupados, int& solActual, int &mejorSol ) {
    for (int i = 0; i < tiempoTareas.size(); ++i){
        if (!funcionariosOcupados[i]) {
            solActual += tiempoTareas[k][i];
            funcionariosOcupados[i] = true;
            if (k == tiempoTareas.size() - 1) {
                if (solActual < mejorSol) mejorSol = solActual;
            }
            else resolver(tiempoTareas, k + 1, funcionariosOcupados, solActual, mejorSol);
            solActual -= tiempoTareas[k][i];
            funcionariosOcupados[i] = false;
        }
    }
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (n == 0) return false;
    
    std::vector<std::vector<int>> tiemposTareas(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> tiemposTareas[i][j];
        }
    }
    std::vector<bool> marcasTareas(n, false);
    int sol = 0;
    int mejorSol = MAX;
    resolver(tiemposTareas, 0, marcasTareas, sol, mejorSol);
    std::cout << mejorSol << std::endl;
    return true;
}

int main() {
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    while (resuelveCaso());
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
}