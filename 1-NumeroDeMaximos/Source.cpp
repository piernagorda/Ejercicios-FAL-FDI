#include <iostream>
#include <fstream> //Para poder leer el fichero de entrada
#include <limits> //Para usar -INFINITO
/*
Autor: Javier Piernagorda
Fecha: 14/1/2022
Correo: jpiernag@ucm.es

En resuelveCaso recibimos los datos de entrada uno a uno (porque no se pueden almacenar en memoria)
y, si es mayor que el maximo actual, actualizamos el nuevo maximo y ponemos que ha salido una vez 
Si el valor de entrada es igual al maximo, incrementamos el numero de veces. En caso de que sea menor
se ignora y se sigue. 

-Coste en tiempo: O(n) donde n es el numero de elementos del fichero
-Coste en memoria: O(1) porque solo necesitamos almacenar el elemento que estamos leyendo

Notas: hay que fijar la variable maximo a -INFINITO (esto se hace incluyendo <limits> y numeric_limits<int>::min().
	   Otra solucion menos fiable es fijar el valor a un negativo grande (por ej: maximo = -10000000) pero esto es
	   menos fiable. La ultima opcion es asignar que el maximo es el primer numero que entra.
*/
void resuelveCaso() {
	int n, maximo = std::numeric_limits<int>::min(), numVeces=0;
	std::cin >> n;
	while (n != 0) {
		if (n > maximo) {
			maximo = n;
			numVeces = 1;
		}
		else if (n == maximo)++numVeces;
		std::cin >> n;
	}
	std::cout << maximo << " " << numVeces << std::endl;
}

int main() {
//Si no estamos ejecutando en el juez (el DOMJUDGE) el entorno no tendra definido
//el DOMJUDGE, por lo que cogemos los datos de un fichero y hacemos que el cin entre por ahi
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int n; std::cin >> n;
	for (int i=0;i<n;++i) resuelveCaso();
//Volvemos a dejar la entrada como estaba y hacemos PAUSE para poder leer la consola sin que se cierre
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}