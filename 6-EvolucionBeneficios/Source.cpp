#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 15/1/2022
Correo: jpiernag@ucm.es

Tenemos que recorrer el vector de resultados y meter en el vector solucion aquellos que superen en beneficios a TODOS los anteriores. Por tanto,
no es suficiente que el valor que estemos viendo sea menor que el anterior, sino que hay que llevar la cuenta de cual es el valor maximo hasta ahora.
Como el anyo en la posicion 0 de resultados no se cuenta, asignamos que este ha sido el maximo de ventas y empezamos a iterar desde la posicion 1,
y vamos comparando: si el valor actual es mayor que el maximo, lo metemos (metemos anyoIni, que se pasa por referencia), actualizamos el valor 
maximo a resultados[i] y sumamos +1 a anyoIni para llevar bien la cuenta de anyos que se meten en el vector.

-Coste en tiempo: O(n) donde n es el numero de elementos del vector (esto es, anyoFin-anyoIni +1), porque los comprobamos todos
-Coste en espacio: O(2*n) porque necesitamos almacenar todo el vector de entrada y, en el caso peor, todos los anyos superan a los anteriores
					y el vector solucion es igual al de entrada, por lo que estariamos guardando el vector de entrada dos veces
*/

std::vector<int> beneficios(std::vector<int> const& resultados, int &anyoIni) {
	std::vector<int> retorno;
	++anyoIni;
	int maximoVentas = resultados[0];
	for (int i = 1; i < resultados.size(); ++i) {
		if (resultados[i] > maximoVentas) {
			retorno.push_back(anyoIni);
			maximoVentas = resultados[i];
		}
		++anyoIni;
	}
	return retorno;
}

void resuelveCaso() {
	int anyoIni, anyoFin, tamVector;
	std::cin >> anyoIni >> anyoFin;
	tamVector = anyoFin - anyoIni + 1; //2017-2000 = 17, pero hay 18 anos asique +1
	std::vector<int> resultados(tamVector);
	std::vector<int> sol;
	for (int i = 0; i < tamVector; ++i) std::cin >> resultados[i];
	if (tamVector>1) sol = beneficios(resultados, anyoIni);
	for (int i = 0; i < sol.size(); ++i) std::cout << sol[i] << " ";
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