#include <iostream>
#include <fstream>
#include <vector>

void imprimirSolucion(std::vector<char> const& sol) {
	for (int i = 0; i < sol.size(); ++i) std::cout << sol[i];
	std::cout << "\n";
}

void variacionesSinRepeticion(int numeros, int longitud, std::vector<char> &sol, std::vector<bool> &marcas){
	for (int i = 0; i < numeros; ++i) {
		char c = (i % 26) + 'a';
		if (!marcas[i]) {
			sol.push_back(c);
			marcas[i] = true;
			if (sol.size() == longitud) imprimirSolucion(sol);
			else {
				variacionesSinRepeticion(numeros, longitud, sol, marcas);
			}
			marcas[i] = false;
			sol.pop_back();
		}
	}
}

bool resuelveCaso() {
	int m, n;
	std::cin >> m >> n;
	if (!std::cin) return false;
	std::vector<char> solucion;
	std::vector<bool> marcas(m, false);
	variacionesSinRepeticion(m, n, solucion, marcas);
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());;
#endif // !DOMJUDGE
	while (resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE

}