#include <iostream>
#include <vector>
#include <fstream>

/*
Autor: Javier Piernagorda
Fecha: 15/1/2022
Correo: jpiernag@ucm.es

En el problema los datos los nacimientos de elefantes de cada año. Entonces, en lugar de estar iterando todo el rato sobre el mismo vector
para cada consulta, lo mas logico es que en cada posicion guardemos las sumas parciales. Asi, al recibir las consultas, simplemente tenemos
que hacer la resta ultimoAnyo - primerAnyo de las consultas y ya. Sin embargo, la implementacion tiene un poco de miga: para evitar llenar 
todo de condicionales, es mas comodo poner un 0 en la posicion 0 y asi no tenemos que evitar comprobar que no entramos en posiciones negativas.
Ademas, el tamano de un vector sera: anyoFin - anyoIni + 1, porque entre 2000 y 2017 hay 18 anos (y la resta daria solo 17) por lo que sumamos 1
y ademas hay que sumarle otro +1 por el 0 de la posicion 0. Entonces, hacemos las sumas parciales tal cual se reciben los datos por entrada y
al hacer consultas solo tenemos que hacer restas (eso si, ojo al calcular las posiciones a las que accedemos porque es facil calcular erroneamente)

-Coste en tiempo: O(n) donde n es el numero de elementos del vector porque cuando recibimos un dato por entrada, accedemos al anterior tambien y lo sumamos
-Coste en espacio: O(n) porque almacenamos los n elementos de entrada en un vector
*/

long long int resolverDudas(int const& posIni, int const& posFin, std::vector<long long int> const& sumasAcumuladas) {
	return sumasAcumuladas[posFin] - sumasAcumuladas[posIni - 1];
}

bool resuelveCaso() {
	int anyoIni, anyoFin, numConsultas, anyoIniConsulta, anyoFinConsulta;
	std::cin >> anyoIni >> anyoFin;
	if (anyoIni==0 && anyoFin == 0) return false;
	int tamVector = anyoFin - anyoIni + 2;
	std::vector<long long int> datos(tamVector);
	datos[0] = 0;
	for (int i = 1; i < tamVector; ++i) {
		std::cin >> datos[i];
		datos[i] += datos[i - 1];
	}
	std::cin >> numConsultas;
	for (int i = 0; i < numConsultas; ++i) {
		int primerAnyo, ultimoAnyo;
		std::cin >> primerAnyo >> ultimoAnyo;
		std::cout << resolverDudas(primerAnyo - anyoIni + 1, ultimoAnyo - anyoIni + 1, datos) << std::endl;
	}
	std::cout << "---" << std::endl;
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while (resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}