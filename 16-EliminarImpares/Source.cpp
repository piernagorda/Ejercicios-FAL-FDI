#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 16/1/2022
Correo: jpiernag@ucm.es

Este problema tiene la misma idea que el de los sensores defectuosos: no podemos usar la funcion erase() propia de los vectores porque cuestan
mucho en caso de que haya que eliminar muchos elementos. Por tanto, llevaremos una variable donde llevamos la posicion de los numeros pares a poner:
esta empieza siendo 0 y si encuentra un elemento que es par, lo pone en esa posicion y suma +1. Asi, tendremos en la 0 -> contadorBuenos los elementos
pares y en el resto del vector tendremos basura que se puede quitar. Luego, hacemos un resize con las posiciones que nos queremos quedar y ya. Se puede
pasar por referencia el vector porque es un gasto de memoria hacer otro vector auxiliar.

-Coste en tiempo: O(n) donde n es el numero de elementos del vector
-Coste en memoria: O(n) porque en el caso peor todos son pares
*/


void resolver(std::vector<int>	&listaAlumnos) {
	//Eliminar los impares!
	int contadorBuenos = 0;
	for (int i = 0; i < listaAlumnos.size(); ++i) {
		if (listaAlumnos[i] % 2 == 0) {
			listaAlumnos[contadorBuenos] = listaAlumnos[i];
			++contadorBuenos;
		}
	}
	listaAlumnos.resize(contadorBuenos);
}

void resuelveCaso() {
	int numAlumnos;
	std::cin >> numAlumnos;
	std::vector<int> listaAlumnos(numAlumnos);
	for (int i = 0; i < numAlumnos; ++i) std::cin >> listaAlumnos[i];
	resolver(listaAlumnos);
	for (int i = 0; i < listaAlumnos.size(); ++i) std::cout << listaAlumnos[i] << " ";
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