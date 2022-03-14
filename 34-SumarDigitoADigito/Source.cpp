#include <iostream>
#include <fstream>

int resolver(int numA, int numB, int llevadas, int sumaTotal, int potencia) {
	int sumaActual = numA % 10 + numB % 10 + llevadas;
	if (numA % 10 != numA || numB % 10 != numB) {
		int llevadasSiguienteLlamada = sumaActual / 10;
		int siguienteSumaTotal = sumaTotal + potencia * (sumaActual % 10);
		int siguientePotencia = potencia * 10;
		return resolver(numA / 10, numB / 10, llevadasSiguienteLlamada, siguienteSumaTotal, siguientePotencia);
	}
	else return sumaTotal+potencia*(numA+numB+llevadas);
} 

void resuelveCaso() {
	int numA, numB;
	std::cin >> numA >> numB;
	std::cout << resolver(numA, numB, 0, 0, 1) << std::endl;
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