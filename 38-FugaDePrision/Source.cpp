#include <iostream>
#include <fstream>
#include <vector>

int resolver(std::vector<char> const& listaPresos, int ini, int fin) {
	int m = (ini + fin) / 2;
	std::cout << "ACCEDIENDO A M " << m << std::endl;
	int a = listaPresos[m];
	if (ini == fin) {
		if (a == ini) return -1;
		else return ini;
	}
	else {
		if (a == m) return resolver(listaPresos, m + 1, fin);
		else {
			return resolver(listaPresos, ini, m);
		}
	}
}

void resuelveCaso() {
	char ini, fin;
	std::cin >> ini >> fin;
	std::vector<char> listaPresos;
	char temp;
	std::cin >> temp;
	while (temp <= fin) {
		listaPresos.push_back(temp);
		std::cin >> temp;
	}
	if (resolver(listaPresos, 0, listaPresos.size() - 1) == -1) {
		std::cout << ini - 1 << std::endl;
	}
}

int main() {
	//Si no estamos ejecutando en el juez (el DOMJUDGE) el entorno no tendra definido
	//el DOMJUDGE, por lo que cogemos los datos de un fichero y hacemos que el cin entre por ahi
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
	//Volvemos a dejar la entrada como estaba y hacemos PAUSE para poder leer la consola sin que se cierre
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}