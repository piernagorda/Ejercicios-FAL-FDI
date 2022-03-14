#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 15/1/2022
Correo: jpiernag@ucm.es

Mientras que una solucion bastante facil seria ir metiendo los valores correctos en el vector tal cual entran por la entrada
parece que no es una solucion valida. Asi, lo correcto es empezar desde la posicion 0 y llevar el numero de posiciones "buenas"
del vector, es decir, el # de valores correctos que vamos encontrando. Asi, vamos copiando al inicio del vector los valores correctos
y al final, hacemos un resize (funcion de std::vector) que le dice al vector: de 0 a posicionesCorrectas es el nuevo tamano del vector,
el resto a la basura. Asi, los valores erroneos se quedaran al final del vector y al hacer resize se eliminaran.

-Coste en tiempo: O(n) donde n es el numero de elementos. En cualquier caso recorremos el vector entero
-Coste en espacio: O(n) porque almacenamos los n elementos del vector

Nota: no se debe usar erase() (otra funcion de std::vector) porque cuesta bastante en tiempo
*/

void resolver(std::vector<int>& datos, int valorErroneo) {
	int posicionesCorrectas = 0;
	for (int i = 0; i < datos.size(); ++i) {
		if (datos[i] != valorErroneo) {
			datos[posicionesCorrectas] = datos[i];
			++posicionesCorrectas;
		}
	}
	datos.resize(posicionesCorrectas);
}

void resuelveCaso() {
	int tamVector, valorErroneo;
	std::cin >> tamVector >> valorErroneo;
	std::vector<int> datos(tamVector);
	for (int i = 0; i < tamVector; ++i) std::cin >> datos[i];
	resolver(datos, valorErroneo);
	std::cout << datos.size() << std::endl;
	for (int i = 0; i < datos.size(); ++i) std::cout << datos[i] << " ";
	std::cout << "\n";
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int numCasos; std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}