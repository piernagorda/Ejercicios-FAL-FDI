#include <iostream>
#include <fstream>
#include <vector>

bool esValida(std::vector<int> const& sol, std::vector<int> const& vecesUsado, int i, std::vector<int> const& soporteDeLluvia, std::vector<int> const& probabilidadLluvia) {
	if (soporteDeLluvia[i] < probabilidadLluvia[sol.size()-1]) return false;
	if (sol.size()>=2 && sol[sol.size() - 1] == sol[sol.size() - 2]) return false;
	if (vecesUsado[i] >= 2 + sol.size() / 3) return false;
	return true;
}

int resolver(std::vector<int> const& probabilidadLluvia, std::vector<int> const& soporteDeLluvia, std::vector<int> &vecesUsado, std::vector<int> &sol) {
	int numSoluciones = 0;
	for (int i = 0; i < soporteDeLluvia.size(); ++i) {
			sol.push_back(i);
			++vecesUsado[i];
			if (esValida(sol, vecesUsado, i, soporteDeLluvia, probabilidadLluvia)) {
				if (sol.size() == probabilidadLluvia.size()) { 
					if (sol[sol.size() - 1] != sol[0]) {
						++numSoluciones;
					}
				}
				else numSoluciones+=resolver(probabilidadLluvia, soporteDeLluvia, vecesUsado, sol);
			}
			sol.pop_back();
			--vecesUsado[i];
	}
	return numSoluciones;
}

bool resuelveCaso() {
	int numeroDias, numeroAbrigosDisponibles;
	std::cin >> numeroDias >> numeroAbrigosDisponibles;
	if (numeroDias == 0 && numeroAbrigosDisponibles == 0) return false;
	std::vector<int> probabilidadLluvia(numeroDias);
	std::vector<int> soporteDeLluvia(numeroAbrigosDisponibles);
	std::vector<int> vecesUsado(numeroAbrigosDisponibles, 0);
	std::vector<int> sol;
	for (int i = 0; i < numeroDias; ++i) std::cin >> probabilidadLluvia[i];
	for (int i = 0; i < numeroAbrigosDisponibles; ++i) std::cin >> soporteDeLluvia[i];
	int solucion = resolver(probabilidadLluvia, soporteDeLluvia, vecesUsado, sol);
	if (solucion==0) std::cout << "Lo puedes comprar" << std::endl;
	else std::cout << solucion << std::endl;
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