#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 19/1/2022
Correo: jpiernag@ucm.es

El problema es tan facil como que hay que hallar el segmento de longitud L que sea maximo. Para eso, sumamos las L primeras posiciones,
asignamos que ese es el desnivel maximo tras hacerlo y comenzamos desde la posicion L hasta n-1, restando a la suma actual de desnivel la
posicion 0 y sumando la L (y comprobamos si el desnivel es mayor que el maximo desnivel encontrado y si si, actualizamos los indices que tocan:
el desnivel maximo, la posicion ini1 e ini2, y en caso de que sean iguales solo se cambia el ini2), luego en cuando i=L+1 restaremos el valor
de i=1 y sumaremos el de i=L+1, etc.

-Coste en tiempo: O(n) donde n es el numero de elementos y el vector solo lo recorremos una vez
-Coste en espacio: O(n) porque hay que almacenar los datos de entrada, que tienen tamano n
*/

void resolver(std::vector<int> const& etapas, int longitudTramo) {
	int maximoDesnivel = 0, desnivelActual = 0, posIni1 = 0, posIni2 = 0;
	//Sumamos las L primeras posiciones
	for (int i = 0; i < longitudTramo; ++i) desnivelActual += etapas[i];
	maximoDesnivel = desnivelActual;
	for (int i = longitudTramo; i < etapas.size(); ++i) {
		desnivelActual -= etapas[i - longitudTramo];
		desnivelActual += etapas[i];
		if (desnivelActual > maximoDesnivel) {
			maximoDesnivel = desnivelActual;
			posIni1 = i - longitudTramo + 1;
			posIni2 = i - longitudTramo +1;
		}
		else if (desnivelActual == maximoDesnivel) posIni2 = i - longitudTramo + 1;
	}
	std::cout << maximoDesnivel << " " << posIni1 << " " << posIni2 << std::endl;
}

bool resuelveCaso() {
	int numKm,longitudTramo;
	std::cin >> numKm >> longitudTramo;
	if (numKm == 0 && longitudTramo == 0) return false;
	std::vector<int> etapas(numKm);
	for (int i = 0; i < numKm; ++i) std::cin >> etapas[i];
	resolver(etapas, longitudTramo);
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