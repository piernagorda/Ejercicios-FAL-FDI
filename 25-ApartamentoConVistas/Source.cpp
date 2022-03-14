#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*
Autor: Javier Piernagorda
Fecha: 19/1/2022
Correo: jpiernag@ucm.es

Nos dan una lista de pisos desde el interior hacia la costa, y tenemos que decir, desde la costa, los pisos disponibles que hay que no tengan
un edificio delante que los tape. Entonces, no tiene sentido empezar desde 0->n-1 porque, si encontramos un piso que este disponible, lo meteriamos
al vector solucion, y si el siguiente lo cumple igual...pero en el momento en que encontremos un edificio que obstruye las vistas, habria que vaciar
el vector solucion entero. Entonces, tiene sentido empezar desde la costa e ir recorriendo hacia el interior guardando la altura maxima. Entonces, 
si hay algun edificio que no supera esa altura maxima -> tendra la vista de la playa obstruida -> no es un edificio valido

-Coste en tiempo: O(n) porque recorremos los n elementos una sola vez, de n-1 a 0
-Coste en espacio: O(2n) porque, en el caso peor, todos los elementos cumplen la condicion y en el vector solucion almacenamos todos los elementos, es
					decir, guardamos el vector de edificios (tamano O(n)) y el vector solucion, que tambien tiene tamano O(n)
*/


struct tPiso {
	std::string nombre;
	int altura;
	int disponible;
};

void resolver(std::vector<tPiso> const& listaPisos) {
	std::vector<std::string> listaPisosValidos;
	int alturaMax = 0;
	for (int i = listaPisos.size() - 1; i >= 0; --i) {
		if (i == listaPisos.size() - 1 && listaPisos[i].disponible != -1) {
			listaPisosValidos.push_back(listaPisos[i].nombre);
			alturaMax = listaPisos[i].altura;
		}
		else {
			if (listaPisos[i].disponible != -1 && listaPisos[i].disponible > alturaMax) listaPisosValidos.push_back(listaPisos[i].nombre);
			if (listaPisos[i].altura > alturaMax)alturaMax = listaPisos[i].altura;
		}
	}
	if (listaPisosValidos.size() < 1) std::cout << "Ninguno";
	else {
		std::cout << listaPisosValidos.size() << std::endl;
		for (int i = 0; i < listaPisosValidos.size(); ++i) std::cout << listaPisosValidos[i] << " ";
	}
	std::cout << "\n";
}

bool resuelveCaso() {
	int numApartamentos;
	std::cin >> numApartamentos;
	if (numApartamentos == 0) return false;
	std::vector<tPiso> listaPisos(numApartamentos);
	for (int i = 0; i < numApartamentos; ++i) std::cin >> listaPisos[i].nombre >> listaPisos[i].altura >> listaPisos[i].disponible;
	resolver(listaPisos);
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