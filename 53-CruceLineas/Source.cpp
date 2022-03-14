#include <iostream>
#include <fstream>
#include <vector>

struct tDatos {
	int ini = -1;
	int fin = -1;
	bool seCruzan;
};

tDatos resolver(std::vector<int> const& rectaA, std::vector<int> const& rectaB, int ini, int fin) {
	std::cout << "ini: " << ini << " fin: " << fin << std::endl;
	if (ini + 1 == fin) {
		if (rectaA[ini] == rectaB[ini]) return { ini, ini, true };
		else if (rectaA[fin] == rectaB[fin]) return { fin, fin, true };
		else return { ini, fin, false };
	}
	else {
		int m = (ini + fin) / 2;
		std::cout<<"Mitad: "<<m<<std::endl;
		if (rectaA[m] == rectaB[m]) return { m, m, true };
		else {
			if (std::abs(rectaA[m] - rectaB[m]) > std::abs(rectaA[m + 1] - rectaB[m + 1])) return resolver(rectaA, rectaB, m, fin); //Las rectas se cruzararan a la dcha
			else   return resolver(rectaA, rectaB, ini, m); //Las rectas se cruzaran a la izquierda
		}
	}
}

bool resuelveCaso() {
	int tamVector;
	std::cin >> tamVector;
	if (tamVector == 0) return false;
	std::vector<int> rectaA(tamVector);
	std::vector<int> rectaB(tamVector);
	for (int i = 0; i < tamVector; ++i) std::cin >> rectaA[i];
	for (int i = 0; i < tamVector; ++i) std::cin >> rectaB[i];
	tDatos sol = resolver(rectaA, rectaB, 0, tamVector - 1);
	if (sol.seCruzan) std::cout << "SI " << sol.ini << std::endl;
	else std::cout << "NO " << sol.ini << " "<<sol.fin << std::endl;
	std::cout << "---" << std::endl;
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