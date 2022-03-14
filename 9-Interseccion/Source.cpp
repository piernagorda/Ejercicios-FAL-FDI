#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/*
Autor: Javier Piernagorda
Fecha: 15/1/2022
Correo: jpiernag@ucm.es

Para poder solucionar este problema primero debemos ordenar lo vectores con sort. ¿Por que? Porque la funcion sort() tiene
de media coste en O(nlogn), por lo que ordenar los dos vectores sale a coste O(2nlogn). Si lo hacemos a lo bruto, en el caso peor,
comparamos cada elemento de A con todos los elementos de B, es decir, cada elemento hace que recorramos B n veces (siendo n el
numero de elementos de B). Por tanto, esto se nos va a O(n^2). Sin embargo, si los ordenamos antes, con este algoritmo, si los valores
son iguales se meten en el vector solucion. Si A[i]<B[j], entonces, al estar ordenados, es imposible que vayamos a encontrar el valor
de A[i] en lo que queda de B. Por tanto, avanzamos ambos indices. Si seguimos, recorremos min(tamA, tamB) elementos, y esto esta en O(n).
Entonces:

-Coste en tiempo: O(n+nlogn) = O(2nlogn)
-Coste en espacio: O(m+n+min(n, m))) ya que tenemos 3 vectores: A, B y la solucion. Siendo m el tamano de uno (A o B) y
					n el tamano del otro, la interseccion tendra, en el caso peor,
					el tamano del menor (es decir, A esta contenido en B o viceversa)
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
		else if (A[indiceA] < B[indiceB]) ++indiceA;
		else ++indiceB;
	}
	return solucion;
}

void resuelveCaso() {
	std::vector<int> A;
	std::vector<int> B;
	int n; std::cin >> n;
	while (n != 0) {
		A.push_back(n);
		std::cin >> n;
	}
	std::cin >> n;
	while (n != 0) {
		B.push_back(n);
		std::cin >> n;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	std::vector<int> interseccion;
	interseccion = resolver(A, B);
	for (int i = 0; i < interseccion.size(); ++i) std::cout << interseccion[i] << " ";
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