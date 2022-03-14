#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 19/1/2022
Correo: jpiernag@ucm.es

El problema es bastante sencillo: recorremos el vector y vamos viendo si al sumar el siguiente elemento, la suma es mayor que 0 o no.
En caso de que si, se suma el elemento y se sigue. En caso de que no, se pone la suma actual a 0 de nuevo. Como nos interesa saber
cual es el valor maximo, el numero de elementos que entran en esa secuencia y su posicion de inicio, hay que guardarlos y actualizar
cuando toque. 

-Coste en tiempo: O(n) siendo n el numero de elementos del vector, porque recorremos el vector una sola vez
-Coste en espacio: O(n) porque necesitamos almacenar el vector de elementos
*/

void resolver(std::vector<int> const& numeros) {
	int sumaMaxima = 0, sumaActual = 0, posIni = -1, posIniMaxima = -1, numerosTenidosEnCuenta = 0, numerosTenidosEnCuentaMax = 0;
	for (int i = 0; i < numeros.size(); ++i) {
		if ((sumaActual + numeros[i]) > 0) {
			if (sumaActual == 0) posIni = i;
			sumaActual += numeros[i];
			++numerosTenidosEnCuenta;
			if (sumaActual > sumaMaxima) {
				posIniMaxima = posIni;
				sumaMaxima = sumaActual;
				numerosTenidosEnCuentaMax = numerosTenidosEnCuenta;
			}
			else if (sumaActual == sumaMaxima && numerosTenidosEnCuenta < numerosTenidosEnCuentaMax) {
					posIniMaxima = posIni;
					sumaMaxima = sumaActual;
					numerosTenidosEnCuentaMax = numerosTenidosEnCuenta;
			}
		}
		else {
			sumaActual = 0;
			numerosTenidosEnCuenta = 0;
		}
	}
	std::cout << sumaMaxima << " " << posIniMaxima << " " << numerosTenidosEnCuentaMax << std::endl;
}

bool resuelveCaso(){
	int tamVector;
	std::cin >> tamVector;
	if (!std::cin) return false;
	std::vector<int> numeros;
	for (int i = 0; i < tamVector; ++i) {
		int num;
		std::cin >> num;
		numeros.push_back(num);
	}
	resolver(numeros);
	return true;
}

int main() {
	//Si no estamos ejecutando en el juez (el DOMJUDGE) el entorno no tendra definido
	//el DOMJUDGE, por lo que cogemos los datos de un fichero y hacemos que el cin entre por ahi
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while( resuelveCaso());
	//Volvemos a dejar la entrada como estaba y hacemos PAUSE para poder leer la consola sin que se cierre
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}