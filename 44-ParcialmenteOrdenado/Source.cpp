#include <fstream>
#include <iostream>
#include <vector>

struct tPareja {
	int maximo;
	int minimo = 0;
	bool seCumple = false;
};

tPareja comprobarDerecha(std::vector<int> const& datos, int ini, int fin) {
	if (ini + 1 == fin) {
		std::cout<<"Acciendo a "<<ini<<" "<<fin<<std::endl;
		std::cout << "Valor de datos[ini]: " << datos[ini] << std::endl;
		std::cout << "Valor de datos[fin]: " << datos[fin] << std::endl;
		
		return  { 0, 0, datos[fin] >= datos[ini] };
	}
	else {
		int m = (ini + fin - 1) / 2;
		std::cout << "ini: " << ini << " fin: " << fin << std::endl;
		std::cout << "Mitad: " << m << std::endl;
		tPareja derecha=comprobarDerecha(datos, m + 1, fin);
		std::cout << "Paso de aqui" << std::endl;
		if (derecha.seCumple) {
			tPareja izquierda = comprobarDerecha(datos, ini, m);
			if (izquierda.seCumple) if (izquierda.minimo <= derecha.minimo && derecha.maximo >= izquierda.maximo) return { derecha.maximo, izquierda.minimo, true };
			else return { 0, 0, false };
		}
		else return { 0, 0, false };
	}
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (n == 0) return false;
	else {
		std::vector<int> numeros;
		while (n != 0) {
			numeros.push_back(n);
			std::cin >> n;
		}
		if (comprobarDerecha(numeros, 0, numeros.size() - 1).seCumple) std::cout << "SI" << std::endl;
		else std::cout << "NO" << std::endl;
	}
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