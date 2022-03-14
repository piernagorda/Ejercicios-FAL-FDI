#include <iostream>
#include <fstream>
#include <vector>

void resolver(std::vector<int> &naves, int ini, int fin) {
	if (ini + 1 == fin) {
		if (naves[ini]==1)
	}
}

bool resuelveCaso() {
	int n;
	std::cin >> n;
	if (!std::cin >> n) return false;
	std::vector<int> naves(n);
	for (int i = 0; i < n; ++i) std::cin >> naves[i];
	int sol = resolver(naves, 0, n - 1);
	return true;
}

int main() {
#ifndef DOMJUDGE
	std::ifstream in("C:/users/javie/desktop/datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while (resuelveCaso());
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}