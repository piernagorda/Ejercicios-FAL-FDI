#include <iostream>
#include <fstream>
#include <vector>

/*
Tenemos que ver cual es la secuencia mas larga de edificios que superan la altura h. Para eso, si un elemento es mas alto que la altura,
sumamos al contador actual. En caso de que ese contador sea mayor que el contador maximo, actualizamos la posicion inicial del intervalo
y la distancia maxima. En caso de que no simplemente se suma. Y si no se cumple la condicion del edificio > altura, se pone el contador a 0
de nuevo.

-Coste en tiempo: O(n) donde n es el numero de edificios. Tiene este coste porque recorremos los elementos del vector una sola vez
-Coste en espacio: O(n) porque tenemos que alamacenar los n edificios

Nota: se puede usar para devolver los valores un struct, una pareja o simplemente un void como he hecho yo.
*/

void resolver(std::vector<int> const& edificios, int altura) {
	int posIniMax=-1, distanciaMax=0, distanciaActual=0;
	for (int i = 0; i < edificios.size(); ++i) {
		if (edificios[i] > altura) { //Si la altura del edificio actual es mayor que la de la nave
			if (posIniMax == -1) { //Si es la primera vez que recorremos el vector
				++distanciaActual;
				++distanciaMax;
				posIniMax = i;
			}
			else { //Sino, sumamos a la distancia actual
				++distanciaActual;
				if (distanciaActual > distanciaMax) {
					distanciaMax = distanciaActual;
					posIniMax = i - distanciaActual+1;
				}
			}
		}
		else distanciaActual = 0;
	}
	std::cout << posIniMax << " " << posIniMax + distanciaMax - 1 << std::endl;
}

void resuelveCaso() {
	int numEdificios, altura;
	std::cin >> numEdificios >> altura;
	std::vector<int> edificios(numEdificios);
	for (int i = 0; i < numEdificios; ++i) std::cin >> edificios[i];
	resolver(edificios, altura);
}

int main() {
	//Si no estamos ejecutando en el juez (el DOMJUDGE) el entorno no tendra definido
	//el DOMJUDGE, por lo que cogemos los datos de un fichero y hacemos que el cin entre por ahi
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	int n; std::cin >> n;
	for (int i = 0; i < n; ++i) resuelveCaso();
	//Volvemos a dejar la entrada como estaba y hacemos PAUSE para poder leer la consola sin que se cierre
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}