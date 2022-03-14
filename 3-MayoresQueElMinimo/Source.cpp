#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 14/1/2022
Correo: jpiernag@ucm.es

El problema consiste en sumar todos los valores salvo el minimo. Como hay usar una funcion externa mas alla de resuelveCaso y tenemos
que devolver dos valores (la suma y los valores tenidos en cuenta) se puede usar una tupla o un struct (el metodo elegido). La resolucion
se basa en asignar el valor inicial del vector como minimo, poner que aparece una vez, y si se van encontrando valores menores que el minimo
se anade a la suma total el que hasta entonces era el minimo multiplicado por el numero de veces que habia aparecido. Una vez hecho esto,
asignamos el nuevo minimo y seguimos. En caso de que el valor que estamos mirando no sea menor que el minimo simplemente se suma y se hace +1
a los datos tenidos en cuenta.

-Coste en tiempo: O(n) donde n es el numero de elementos del vector. Siempre vamos a recorrer el vector entero y una sola vez.
-Coste en espacio: O(n) donde n es el numero de elementos del vector, porque tenemos que almacenarlos todos

Nota: para la suma hay que usar long long int, porque sino, con vectores grandes, la suma desborda al tipo int
*/


struct tDatos {
	long long int suma=0;
	int datosTenidosEnCuenta=0;
};

tDatos calcular(std::vector<int> const& numeros) {
	tDatos retorno;
	int min = numeros[0], numVecesAparecido = 1;
	for (int i = 1; i < numeros.size(); ++i){
		if (numeros[i] < min) {
			//Primero asignamos a una variable temporal el minimo y luego multiplicamos, porque sino se puede desbordar
			long long int temp = min;
			temp*=numVecesAparecido;
			//Actualizamos la variable que devolveremos en la funcion
			retorno.suma += temp;
			retorno.datosTenidosEnCuenta += numVecesAparecido;
			//Actualizamos el minimo
			min = numeros[i];
			numVecesAparecido = 1;
		}
		else if (numeros[i] == min) ++numVecesAparecido;
		else {
			retorno.suma += numeros[i];
			++retorno.datosTenidosEnCuenta;
		}
	}
	return retorno;
}

void resuelveCaso() {
	int tamVector;
	std::cin >> tamVector;
	std::vector<int> numeros(tamVector);
	for (int i = 0; i < tamVector; ++i) std::cin >> numeros[i];
	tDatos solucion = calcular(numeros);
	std::cout << solucion.suma <<" "<< solucion.datosTenidosEnCuenta << std::endl;
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