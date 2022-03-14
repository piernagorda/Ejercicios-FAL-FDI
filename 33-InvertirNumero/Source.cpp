#include <iostream>
#include <fstream>

/*
Autor: Javier Piernagorda
Fecha: 17/1/2022
Correo: jpiernag@ucm.es

El problema en si es muy sencillo al hacerse con una recursion no final (no especifican en el problema que tipo de recursion hay que usar). Ademas
dudo que este problema se pueda hacer con recursion final. En el caso base (numero%10==numero) se devuelve el numero y en el resto de casos, se 
devuelve el digito actual * 10 * potencia. Ojo! Se puede usar math.pow() para calcular la potencia, pero es totalmente ineficiente. Basta con poner
que potencia = 1, y cuando se vuelve del caso base, se va multiplicando potencia * 10. El operador ^ NO hace la potencia (por ej, 10^3 no da 1000, porque
el operador ^ es una OR exclusiva bit a bit).

-Coste de la solucion: O(logO(N)). Se define la recurrencia como: T(1) = C1 si n<10; T(n) = C2*T(n/10), y tras desarrollar, se queda en O(nlogn)
*/


int resolver(int numero, int &potencia) {
	if (numero % 10 == numero) return numero;
	else {
		int digito = numero % 10;
		int retorno = resolver(numero / 10, potencia);
		potencia *= 10;
		return digito * potencia + retorno;
	}
}

bool resuelveCaso() {
	int numero;
	std::cin >> numero;
	if (numero == 0)return false;
	int potencia = 1;
	std::cout << resolver(numero, potencia) << std::endl;
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