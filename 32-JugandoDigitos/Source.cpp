#include <iostream>
#include <fstream>
/*
Autor: Javier Piernagorda
Fecha: 17/1/2022
Correo: jpiernag@ucm.es

Si el digito es impar le restamos uno y sino le sumamos uno. Como se nos pide recursion NO final, el valor que obtengamos como resultado ha de obtenerse
tras bajar hasta el fondo (hasta el ultimo digito del numero) y de ahi, empezar a construir la solucion. Por tanto, cuando llegamos al fondo simplemente
devolvemos el numero (el caso base es cuando el numero que se recibe es menor que 10, entonces numero%10 == numero, porque numero/10 = 0 y su resto es el
propio numero, que obtenemos con el modulo). Luego, tras obtener el caso base, que sera el numero mas a la izquierda de todos, hay que ir multiplicandolo
por 10 y sumarle el digito actual. Asi, vamos desplazando el caso base a la izquierda, donde le corresponde.

-Coste en tiempo: Caso base: T(0) = C1; Caso recursivo: C2*T(n/10); Entonces: T(n) = C2*T(n/10) = C2*C2*T((n/10)/10)= ... C2*C2*...*C2*T(1) = C2*(n-1) + C1
				  El tamano del problema es la longitud del numero, que va disminuyendo en uno por cada llamada recursiva. Entonces, el coste que tendra
				  cada llamada sera un coste constante C2 (las operaciones realizadas) + el coste de su siguiente llamada. Esto esta en O(logn)
*/

int resolverNoFinal(int numero) {
	if (numero % 10 == numero) {//Caso base
		if (numero % 2 == 0) return numero+1;
		else return numero-1;
	}
	else {
		int digito = numero % 10;
		if (digito % 2 == 0) ++digito;
		else --digito;
		return resolverNoFinal(numero / 10)*10+digito;
	}
}

void resuelveCaso() {
	int numero;
	std::cin >> numero;
	std::cout << resolverNoFinal(numero) << std::endl;
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
