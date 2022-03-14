#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/*
Autor: Javier Piernagorda
Fecha: 16/1/2022
Correo: jpiernag@ucm.es

Tenemos que ver que valor se repite mas en el vector y en caso de que se repitan dos valores el mismo # de veces, hay que coger el de menor valor.
Hacer esto sin ordenar el vector previamente requeriria tener un vector adicional para ir contando repeticiones, lo que no es practico. Por eso,
llamamos a sort() y lo ordenamos. Esto tiene coste O(nlogn). Luego simplemente lo vamos recorriendo y contando las repeticiones del valor actual
y vemos si es igual al anterior. En caso de que si, vamos sumando a su contador. Si ese contador llega a igualar al contador de repeticiones maximas,
comparamos con el valor que teniamos guardado hasta entonces (ganara el que sea menor). Si el contador llega a superar al contador de repeticiones maximas
automaticamente se actualiza. En caso de que el elemento actual no sea igual al anterior, al estar ordenado, simplemente ponemos el contador actual a 1.

-Coste en tiempo: O(2nlogn) donde n es el numero de elementos, y porque tenemos el coste de ordenar (O(nlogn) y luego lo recorremos 
					de nuevo, por lo que se recorren los elementos otra vez
-Coste en espacio: O(n) porque tenemos que almacenar el vector de elementos.
*/

int resolver(std::vector<int> const& accidentes) {
	int valorMasAccidentes=accidentes[0], repeticionesMaximas=1, repeticionesActuales = 1;
	for (int i = 1; i < accidentes.size(); ++i) {
		if (accidentes[i] == accidentes[i - 1]) {
			++repeticionesActuales;
			if (repeticionesActuales == repeticionesMaximas) {
				if (accidentes[i] <= valorMasAccidentes) {
					valorMasAccidentes = accidentes[i];
					repeticionesMaximas = repeticionesActuales;
				}
			}
			else if (repeticionesActuales > repeticionesMaximas) {
				repeticionesMaximas = repeticionesActuales;
				valorMasAccidentes = accidentes[i];
			}
		}
		else repeticionesActuales = 1;
	}
	return valorMasAccidentes;
}

bool resuelveCaso() {
	int tamVector;
	std::cin >> tamVector;
	if (tamVector == -1)return false;
	std::vector<int> accidentes(tamVector);
	for (int i = 0; i < tamVector; ++i) std::cin >> accidentes[i];
	sort(accidentes.begin(), accidentes.end());
	std::cout << resolver(accidentes) << std::endl;
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