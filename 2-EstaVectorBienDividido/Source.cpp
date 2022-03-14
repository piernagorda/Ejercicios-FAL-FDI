#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 14/1/2022
Correo: jpiernag@ucm.es

Se trata de ver si todos los valores a partir de la posicion p (no incluida) son mayores *estrictos* que todos los de las posiciones 0 hasta p (incluida)
Asi, solo hay que buscar el mayor elemento del lado izquierdo hasta p y, si todos los de la derecha son mayores que ese valor, tenemos claro que es mayor
que el resto de valores de la izquierda.

-Coste en tiempo: O(n) siendo n el numero de elementos, porque en el caso peor esta bien dividido y tenemos que recorrerlos todos
-Coste en espacio: O(n) ya que tenemos que almacenar los n elementos del vector en memoria
*/

//Se recibe el vector por referencia y no se modifica (asi no hacemos copia del vector, lo accedemos directamente y no permitimos modificar valores)
//Paso por referencia la posicion para reutilizarla y no tener que crear una nueva variable. Esto es opcional
bool estaBienDividido(std::vector<int> const& numeros, int &posicion) {
	bool estaBienDividido = true; //Asumimos que esta bien dividido de inicio
	int maximoHastaPosicion = numeros[0]; //Asignamos el maximo como numeros[0], pero podria asignarse tambien a -INFINITO
	
	//Recorremos desde 0 hasta p (incluido!) y nos quedamos con el maximo
	for (int i = 0; i <= posicion; ++i) if (numeros[i] > maximoHastaPosicion) maximoHastaPosicion = numeros[i];
	++posicion; //Como ahora queremos ver desde p+1, aumentamos la posicion
	
	//Recorremos desde p+1 hasta el ultimo elemento (tam del vector - 1) y salimos en cuanto no esta bien dividido
	for (posicion; posicion < numeros.size(); ++posicion) {
		if (numeros[posicion] <= maximoHastaPosicion) {
			estaBienDividido = false;
			break;
		}
	}
	return estaBienDividido;
}

void resuelveCaso() {
	int tamVector, posicion;
	std::cin >> tamVector >> posicion; //Recibimos del fichero el tamano y la posicion a mirar
	std::vector<int> numeros(tamVector); //Inicializamos un vector con el tamano indicado
	for (int i = 0; i < tamVector; ++i) std::cin >> numeros[i]; //Metemos por entrada los numeros al vector
	if (estaBienDividido(numeros, posicion)) std::cout << "SI" << std::endl; //Llamamos a la funcion que comprueba si esta bien dividido
	else std::cout << "NO" << std::endl;
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