#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 15/1/2022
Correo: jpiernag@ucm.es

El problema consiste en decir que valor del dado ha salido mas veces. Hay que tener en cuenta que el dato del valor maximo del dado nos lo dan
para algo, y eso es, para crear un vector donde iremos sumando +1 a cada cara del dado que salga. Si nos dicen que tiene 12 caras, tendremos que hacer
un vector de 12 posiciones (y al recibir la tirada hacer un +1 en repeticiones[temp-1], porque empieza en 0) o hacer como yo: un vector de 13
posiciones donde el 0 no se usa y asi no hay que andar sumando o restando uno. Hay que ir llevando la cuenta del numero maximo de veces que sale una
cara, y al acabar, recorremos de fin a inicio del vector de caras (porque nos piden de mayor a menor la salida) las tiradas que mas se han repetido.
En la solucion propuesta por los profesores primero metes los datos de entrada, luego una vez metidos todos van sumando al vector de repeticiones y
luego, vuelven a recorrerlo para ver cual es el que se repite. Luego, se lo vuelven a recorrer para meter en un vector final de soluciones la solucion final.
Sinceramente encuentro esto terriblemente ineficiente y no lo voy a hacer asi ya que de esta forma son 2 bucle for frente a 4 de los de la solucion propuesta.

-Coste en el tiempo: O(n+m) siendo n el numero de tiradas y m el numero de caras, porque leemos de entrada y sumamos las n tiradas, y luego
					recorremos el vector de caras entero, que es de tamano m. 
-Coste en espacio: O(m) porque solo almacenaremos el vector de repeticiones. No hace falta guardar las tiradas.
*/

bool resuelveCaso() {
	int tamVector, valorMaximo;
	std::cin >> tamVector >> valorMaximo;
	if (tamVector == -1) return false;
	std::vector<int> repeticiones(valorMaximo+1, 0);
	int maximo = -1;
	for (int i = 0; i < tamVector; ++i) {
		int temp;
		std::cin >> temp;
		++repeticiones[temp];
		if (repeticiones[temp] > maximo) maximo = repeticiones[temp];
	}
	for (int i = repeticiones.size()-1; i >0; --i) if (repeticiones[i] == maximo) std::cout << i << " ";
	std::cout << "\n";
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