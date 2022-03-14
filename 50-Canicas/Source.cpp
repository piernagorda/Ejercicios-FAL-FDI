#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct tJugador {
    std::string nombre;
    int numCanicas;
};

tJugador resolver(std::vector<tJugador> const& listaJugadores, int ini, int fin) {
    if (ini + 1 == fin) {
        tJugador retorno;
        if (listaJugadores[ini].numCanicas >= listaJugadores[fin].numCanicas) {
            retorno = listaJugadores[ini];
            retorno.numCanicas += listaJugadores[fin].numCanicas/2;
        }
        else {
            retorno = listaJugadores[fin];
            retorno.numCanicas += listaJugadores[ini].numCanicas / 2;
        }
        return retorno;
    }
    else {
        int m = (ini + fin - 1) / 2;
        tJugador izq = resolver(listaJugadores, ini, m);
        tJugador dcha = resolver(listaJugadores, m + 1, fin);
        if (izq.numCanicas >= dcha.numCanicas) {
            return { izq.nombre, izq.numCanicas + (dcha.numCanicas / 2) };
        }
        else return { dcha.nombre, dcha.numCanicas+(izq.numCanicas / 2) };
    }
}

bool resuelveCaso() {
    int numJugadores;
    std::cin >> numJugadores;
    if (!std::cin) return false;
    std::vector<tJugador> listaJugadores(numJugadores);
    for (int i = 0; i < numJugadores; ++i) std::cin >> listaJugadores[i].nombre >> listaJugadores[i].numCanicas;
    tJugador sol = resolver(listaJugadores, 0, numJugadores - 1);
    std::cout << sol.nombre << " " << sol.numCanicas << std::endl;
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