#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

struct tPersona {
	int altura;
	std::string nombre;
};
//Redefinimos el operador para poder hacer un sort alfabetico
bool operator<(tPersona a, tPersona b) {
	return  a.nombre< b.nombre || (a.nombre == b.nombre && a.nombre < b.nombre);
}

int resolver(std::vector<tPersona> &listaPersonas, int alturaDiferenciadora) {
	int principioBajos = 0, principioAltos = listaPersonas.size() - 1;
	while (principioBajos<=principioAltos) {
		if (listaPersonas[principioBajos].altura <= alturaDiferenciadora) ++principioBajos;
		else{
			if (listaPersonas[principioAltos].altura > alturaDiferenciadora) --principioAltos;
			else {
				std::swap(listaPersonas[principioAltos], listaPersonas[principioBajos]);
				--principioAltos; ++principioBajos;
			}
		}
	}
	return principioBajos;
}

bool resuelveCaso() {
	int numPersonas, alturaDiferenciadora;
	std::cin >> numPersonas >> alturaDiferenciadora;
	if (!std::cin) return false;
	std::vector<tPersona> personas(numPersonas);
	for (int i = 0; i < numPersonas; ++i) std::cin >> personas[i].nombre >> personas[i].altura;
	int pos = resolver(personas, alturaDiferenciadora);
	std::sort(personas.begin(), personas.begin()+pos);
	std::sort(personas.begin()+pos, personas.end());
	std::cout << "Bajos: ";
	for (int i = 0; i < pos; ++i) std::cout << personas[i].nombre << " ";
	std::cout << "\n";
	std::cout << "Altos: ";
	for (int i = pos; i < personas.size(); ++i) std::cout << personas[i].nombre << " ";
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