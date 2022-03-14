#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 16/1/2022
Correo: jpiernag@ucm.es

Se trata de ver que intervalo de longitud paginasQuePuedoLeer es maximo. Por tanto, tenemos que recorrer el vector e ir llevando la suma del intervalo
actual. Si esa suma es mayor que la suma maxima que habiamos hecho hasta ahora, actualizamos el valor maximo de suma y la posicion inicial. Sino simplemente
seguimos sumando. 

-Coste en tiempo: O(n) donde n es el numero de elementos del vector, porque los recorremos todos
-Coste en espacio: O(n) porque almacenamos los n elementos de entrada en un vector
*/

void resolver(std::vector<int> const& paginasLibro, int maximoPaginasPosibles) {
	int contador = 0,  posIni = 0, valorMax = 0;
	for (int i = 0; i < paginasLibro.size(); ++i) {
		if (i < maximoPaginasPosibles) {
			contador += paginasLibro[i];
			valorMax = contador;
		}
		else {
			contador -= paginasLibro[i - maximoPaginasPosibles];
			contador += paginasLibro[i];
			if (contador >= valorMax) {
				posIni = i - maximoPaginasPosibles + 1;
				valorMax = contador;
			}
		}
	}
	std::cout << posIni << std::endl;
}

bool resolverCaso() {
	int paginasLibro, paginasQuePuedoLeer;
	std::cin >> paginasLibro >> paginasQuePuedoLeer;
	if (paginasQuePuedoLeer == 0 && paginasLibro == 0) return false;
	std::vector<int> paginasDelLibro(paginasLibro);
	for (int i = 0; i < paginasLibro; ++i) std::cin>>paginasDelLibro[i];
	resolver(paginasDelLibro, paginasQuePuedoLeer);
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