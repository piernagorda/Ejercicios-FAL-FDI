#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 14/1/2022
Correo: jpiernag@ucm.es

El problema trata de recorrer dos vectores ordenados de menor a mayor e ir metiendolos en el vector solucion sin repetir ningun precio.
Para esto, hay que llevar un indice de cada vector: indiceA (que llamaremos i) e indiceB (que llamaremos j). Puede haber tres casos:
	1-Que A[i] == B[j] -> Metemos A[i] en el vector y aumentamos tanto i como j (podria meterse B[j] en lugar de A[i], es igual)
	2-Que A[i] < B[j] -> Metemos A[i] en el vector porque tiene que estar ordenado de menor a mayor, y aumentamos i
	3-Que A[i] > B[j] -> Metemos B[j] en el vector y aumentamos j
Ademas, hay que tener en cuenta que los vectores pueden tener longitudes distintas. Por eso, tras recorrer ambos a la vez, hay que asegurarse
de que nos los hemos recorrido del todo. Por eso, hay que ver que el indice de A sea igual a A.size() (en ese caso hemos recorrido A entero)
y que B sea igual a B.size(). En caso de no ser una de las dos (no se pueden dar las dos a la vez por la condicion de fin de bucle while), hay que 
recorrerlos e ir metiendo los numeros que falten.

-Coste en tiempo: O(n+m) donde n es el tamano de A y m el tamano de B
-Coste en espacio: O(n+m) idem

Nota: cuidado con los vectores vacios. En resuelve caso no hay que inicializar los vectores con los tamanos que se nos proporcionan porque
	  entonces la funcion resolver llena de ceros el vector solucion. Hay que hacer push_back con un bucle for. Asi, si se especifica que un
	  vector tiene 0 elementos, simplemente se devuelve el otro.
*/

std::vector<int> resolver(std::vector<int> const& A, std::vector<int> const& B) {
	int indiceA = 0, indiceB = 0;
	std::vector<int> solucion;
	while (indiceA < A.size() && indiceB < B.size()) {
		if (A[indiceA] == B[indiceB]) {
			solucion.push_back(A[indiceA]);
			++indiceA;
			++indiceB;
		}
		else {
			if (A[indiceA] < B[indiceB]) {
				solucion.push_back(A[indiceA]);
				++indiceA;
			}
			else {
				solucion.push_back(B[indiceB]);
				++indiceB;
			}
		}
	}
	if (indiceB < B.size()) for (indiceB; indiceB < B.size(); ++indiceB) solucion.push_back(B[indiceB]);
	else if (indiceA < A.size()) for (indiceA; indiceA < A.size(); ++indiceA) solucion.push_back(A[indiceA]);
	return solucion;
}

void resuelveCaso() {
	int tamA, tamB;
	std::cin >> tamA >> tamB;
	std::vector<int> A;
	std::vector<int> B;
	std::vector<int> sol;
	for (int i = 0; i < tamA; ++i) {
		int temp;
		std::cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < tamB; ++i) {
		int temp;
		std::cin >> temp;
		B.push_back(temp);
	}
	if (tamA == 0) sol = B;
	else if (tamB == 0) sol = A;
	else sol = resolver(A, B);
	for (int i = 0; i < sol.size(); ++i)std::cout << sol[i] << " ";
	std::cout << "\n";
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