#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct tPartido {
	bool hayJugadores = false;
	int numPartidos = 0;
	int ronda = 0;
};

tPartido resolver(std::vector<int> const& jugadores, int profundidad, int ini, int fin) {
	if (ini + 1 == fin) {
		tPartido retorno;
		if (jugadores[ini] == 1 && jugadores[fin] == 1) {
			retorno.hayJugadores = true;
			retorno.numPartidos++;
		}
		else if (jugadores[ini] == 1 || jugadores[fin] == 1) retorno.hayJugadores = true;
		retorno.ronda++;
		return retorno;
	}
	else {
		int m = (ini + fin) / 2;
		tPartido partidoIzquierda = resolver(jugadores, profundidad, ini, m);
		tPartido partidoDerecha = resolver(jugadores, profundidad, m+1, fin);
		tPartido retorno;
		if (partidoIzquierda.ronda < profundidad) { //Si estamos aun en la ronda que queremos
			if (partidoDerecha.hayJugadores || partidoIzquierda.hayJugadores) {
				retorno.hayJugadores = true;
				if (partidoDerecha.hayJugadores && partidoIzquierda.hayJugadores) retorno.numPartidos = partidoDerecha.numPartidos + partidoIzquierda.numPartidos + 1;
				else retorno.numPartidos = partidoDerecha.numPartidos + partidoIzquierda.numPartidos;
				retorno.ronda = partidoDerecha.ronda + 1;
				return retorno;
			}
			else {
				retorno.ronda = partidoIzquierda.ronda+1;
				return retorno;
			}
		}
		else { //Sino, devolvemos los partidos hechos hasta entonces y ponemos una ronda no valida
			retorno.numPartidos = partidoIzquierda.numPartidos + partidoDerecha.numPartidos;
			retorno.ronda = profundidad + 1;
			return retorno;
		}
	}
}

bool resolverCaso() {
	int tamVector, profundidad;
	std::cin >> tamVector >> profundidad;
	if (!std::cin) return false;
	std::vector<int> jugadores(tamVector);
	for (int i = 0; i < tamVector; ++i) {
		std::string temp;
		std::cin >> temp;
		if (temp == "NP") jugadores[i] = 0;
		else jugadores[i] = 1;
	}
	int profundidadActual = 0;
	tPartido sol = resolver(jugadores, profundidad, profundidadActual, jugadores.size() - 1);
	std::cout << sol.numPartidos << std::endl;
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while (resolverCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}