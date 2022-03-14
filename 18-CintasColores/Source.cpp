#include <iostream>
#include <fstream>
#include <vector>

struct tCinta {
	char color;
	int numero;
};

void resolver(std::vector<tCinta>& cintas) {
	int posAzules = 0;
	int posRojas = cintas.size() - 1;

	for (int i = 0; i < cintas.size() && i<=posRojas; ++i) {
		if (cintas[i].color == 'r') {
			std::cout << "He encontrado un rojo en la posicion i " << i << " asique me lo llevo a la posicion " << posRojas << std::endl;
			tCinta temp = cintas[posRojas]; //Cogemos el elemento el la posicion roja y lo cambiamos por el de la i
			cintas[posRojas] = cintas[i]; 
			cintas[i] = temp;
			--posRojas;
			std::cout << "La posicion roja ahora es " << posRojas << std::endl;
		}
		else if (cintas[i].color == 'a') {
			tCinta temp = cintas[posAzules];
			cintas[posAzules] = cintas[i];
			cintas[i] = temp;
			++posAzules;
		}
		
		for (int i = 0; i < cintas.size(); ++i) {
			std::cout << cintas[i].color << " ";
		}
		std::cout << "\n";
	}
}

bool resuelveCaso() {
	int numCintas;
	std::cin >> numCintas;
	if (!std::cin) return false;
	std::vector<tCinta> cintas(numCintas);
	for (int i = 0; i < numCintas; ++i) std::cin >> cintas[i].color >> cintas[i].numero;
	resolver(cintas);
	for (int i = 0; i < cintas.size(); ++i) {
		std::cout << cintas[i].color << " ";
	}
	std::cout << "\n";
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