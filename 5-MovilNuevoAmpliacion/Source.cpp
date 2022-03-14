#include <iostream>
#include <fstream>
#include <vector>

/*
Autor: Javier Piernagorda
Fecha: 15/1/2022
Correo: jpiernag@ucm.es

Este ejercicio en realidad es mas facil que el anterior porque no hay que comprobar si los elementos se repiten o no. Simplemente iteramos
cada vector con un indice, vamos comparando y metemos el que sea menor de A[i] - B[j] en el vector solucion. Luego, en caso de no haber
recorrido alguno de los dos vectores completamente, lo recorremos y metemos sus elementos. Es lo mismo que el ejercicio 4 pero mas sencillo.

-Coste en tiempo: O(n+m) donde n es el tamano de A y m el tamano de B
-Coste en espacio: O(2(n+m)) porque guardaremos el vector A, el B y el vector solucion, que tendra el tamano de A + B al permitir repeticiones
*/

std::vector<int> resolver(std::vector<int> const& A, std::vector<int> const& B) {
	std::vector<int> sol;
	int indiceA = 0, indiceB = 0;
	while (indiceA < A.size() && indiceB < B.size()) {
		if (A[indiceA] < B[indiceB]) {
			sol.push_back(A[indiceA]);
			++indiceA;
		}
		else if (A[indiceA] == B[indiceB]) {
			sol.push_back(A[indiceA]);
			sol.push_back(A[indiceA]);
			++indiceA;
			++indiceB;
		}
		else {
			sol.push_back(B[indiceB]);
			++indiceB;
		}
	}
	for (indiceA; indiceA < A.size(); ++indiceA) sol.push_back(A[indiceA]);
	for (indiceB; indiceB < B.size(); ++indiceB) sol.push_back(B[indiceB]);
	return sol;
}

void resuelveCaso() {
	int tamA, tamB;
	std::cin >> tamA >> tamB;
	std::vector<int> A(tamA);
	std::vector<int> B(tamB);
	std::vector<int> sol;
	for (int i = 0; i < tamA; ++i) std::cin >> A[i];
	for (int i = 0; i < tamB; ++i) std::cin >> B[i];
	if (tamA == 0) sol = B;
	else if (tamB == 0) sol = A;
	else sol = resolver(A, B);
	for (int i = 0; i < sol.size(); ++i) std::cout << sol[i] << " ";
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