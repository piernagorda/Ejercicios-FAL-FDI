#include <iostream>
#include <fstream>
#include <vector>

void imprimirSolucion(std::vector<char> const& solucion) {
	for (int i = 0; i < solucion.size(); ++i) std::cout << solucion[i];
	std::cout << "\n";
}

void generarVariacionesConRepeticion(int numeros, int longitud, std::vector<char> &sol) {
	
	for (int i = 0; i < numeros; ++i){
		char c = (i % 26) + 'a';
		sol.push_back(c);
		if (sol.size() == longitud) imprimirSolucion(sol);
		else {
			generarVariacionesConRepeticion(numeros, longitud, sol);
		}
		sol.pop_back();
	}
}

bool resuelveCaso() {
	int numeros, longitud;
	std::cin >> numeros >> longitud;
	if (!std::cin) return false;
	std::vector<char> sol;
	generarVariacionesConRepeticion(numeros, longitud, sol);
	return true;
}

int main() {
	//Si no estamos ejecutando en el juez (el DOMJUDGE) el entorno no tendra definido
	//el DOMJUDGE, por lo que cogemos los datos de un fichero y hacemos que el cin entre por ahi
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE

	while(resuelveCaso());
	//Volvemos a dejar la entrada como estaba y hacemos PAUSE para poder leer la consola sin que se cierre
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}