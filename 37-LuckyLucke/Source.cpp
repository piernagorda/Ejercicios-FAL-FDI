#include <iostream>
#include <fstream>
#include <vector>

/*
int resolverIzq(std::vector<int> const& alturas, int alturaBuscado, int ini, int fin) {
	if (ini >= fin) return ini;
	else if (ini + 1 == fin) return ini;
	else {
		int mitad = (ini + fin - 1) / 2;
		if (alturas[mitad] < alturaBuscado) return resolverIzq(alturas, alturaBuscado, mitad + 1, fin);
		else return resolverIzq(alturas, alturaBuscado, ini, mitad+1);
	}
}

int resolverDcha(std::vector<int> const& alturas, int alturaBuscado, int ini, int fin) {
	if (ini >= fin) return ini;
	else if (ini + 1 == fin) return ini;
	else {
		int mitad = (ini + fin - 1) / 2;
		if (alturaBuscado < alturas[mitad]) return resolverDcha(alturas, alturaBuscado, ini, mitad);
		else return resolverIzq(alturas, alturaBuscado, mitad, fin);
	}
}

bool resolverCaso() {
	int tamVector, alturaBuscado;
	std::cin >> tamVector >> alturaBuscado;
	if (!std::cin) return false;
	std::vector<int> alturas(tamVector);
	for (int i = 0; i < tamVector; ++i) std::cin >> alturas[i];
	
	int posIz = resolverIzq(alturas, alturaBuscado, 0, tamVector);
	if (posIz == alturas.size() || alturas[posIz] != alturaBuscado)std::cout << "NO EXISTE" << std::endl;
	else {
		int posDcha = resolverDcha(alturas, alturaBuscado, 0, tamVector);
		if (posIz == posDcha) std::cout << posIz << std::endl;
		else std::cout << posIz << " " << posDcha << std::endl;
	}

	return true;
}
*/

int resolverIzquierda(std::vector<int> const& datos, int alturaBuscado, int ini, int fin) {
	if (ini == fin) {
		if (datos[ini] == alturaBuscado) return ini;
		else return -1;
	}
	else {
		int m = (ini + fin - 1) / 2;
		if (datos[m] < alturaBuscado) return resolverIzquierda(datos, alturaBuscado, m+1 , fin);
		else return resolverIzquierda(datos, alturaBuscado, ini, m);
	}
}

int resolverDerecha(std::vector<int> const& datos, int alturaBuscado, int ini, int fin) {
	if (ini == fin) {
		if (datos[ini] == alturaBuscado) return ini;
		else return -1;
	}
	else {
		int m = (ini + fin - 1) / 2;
		if (datos[m]>alturaBuscado) return resolverDerecha(datos, alturaBuscado, ini, m);
		else return resolverDerecha(datos, alturaBuscado, m+1, fin);
	}
}

bool resolverCaso() {
	int tamVector, alturaBuscado;
	std::cin >> tamVector >> alturaBuscado;
	if (!std::cin) return false;
	std::vector<int> alturas(tamVector);
	for (int i = 0; i < tamVector; ++i) std::cin >> alturas[i];
	int izq = resolverIzquierda(alturas, alturaBuscado, 0, tamVector - 1);
	if (izq != -1) {
		std::cout << izq << " ";
		int dcha = resolverDerecha(alturas, alturaBuscado, 0, tamVector - 1);
		if (dcha != izq) std::cout << dcha << std::endl;
		else std::cout << "\n";
	}
	else std::cout << "NO EXISTE" << std::endl;
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