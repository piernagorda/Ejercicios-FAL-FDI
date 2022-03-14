#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 14/1/2022
Correo: jpiernag@ucm.es

Tenemos que ver cuantos segmentos cumplen dos condiciones: que el tamano del segmento sea mayor o igual a la longitud que nos
dan para aterrizar y que los valores del segmento disten entre valores consecutivos, como mucho, en una unidad. Por tanto, hemos
de llevar la cuenta y, en el momento en el que el segmento actual es igual a la longitud dada, metemos la posicion de inicio del 
segmento. Esta, en mi caso, se calcula como i-sumaActual+2. Esto se ve claro en el ejemplo:
5 2
5 4 4 5 6
Al llegar a la posicion i=2 ya tenemos un segmento valido, y el inicio del segmento es 0. Sin embargo, la sumaTotal
sera en ese momento 4, por lo que i - sumaTotal = -2, pero queremos el 0, asique hay que sumar 2. 

-Coste en tiempo: O(n) porque recorremos todos los elementos del vector siendo n el numero de elementos
-Coste en espacio: O(n) para almacenar el vector de entrada y, en el caso peor, tenemos la longitud minima L=2 y hay, de cada
3 posiciones consecutivas, 2 que valen y una que no. Por ejemplo, un vector n=13 y L=2 tal que: 0 1 30 3 4 30 6 7 30 9 10 30 12 13
tendria 5 segmentos a guardar, por lo que seria O((n/2)-1)
*/

void resolver(std::vector<int> const& fotos, int numValoresCasiIguales) {
	std::vector<int> solucion;
	int contadorActual=1;
	for (int i = 0; i < fotos.size() - 1; ++i) {
		if (std::abs(fotos[i + 1] - fotos[i]) <= 1) {
			++contadorActual;
			if (contadorActual == numValoresCasiIguales) solucion.push_back(i - contadorActual + 2);
		}
		else contadorActual = 1;
	}
	std::cout << solucion.size()<<" ";
	for (int i = 0; i < solucion.size(); ++i) std::cout << solucion[i] << " ";
	std::cout << "\n";
}

bool resuelveCaso() {
	int numDatos, numValoresCasiIguales;
	std::cin >> numDatos >> numValoresCasiIguales;
	if (numDatos == 0 && numValoresCasiIguales == 0) return false;
	std::vector<int> fotos(numDatos);
	for (int i = 0; i < numDatos; ++i) std::cin >> fotos[i];
	resolver(fotos, numValoresCasiIguales);
	return true;
}

int main() {
	//Si no estamos ejecutando en el juez (el DOMJUDGE) el entorno no tendra definido
	//el DOMJUDGE, por lo que cogemos los datos de un fichero y hacemos que el cin entre por ahi
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while (resuelveCaso());
	//Volvemos a dejar la entrada como estaba y hacemos PAUSE para poder leer la consola sin que se cierre
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}