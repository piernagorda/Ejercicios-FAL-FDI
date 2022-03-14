#include <iostream>
#include <vector>
#include <fstream>
#include <string>

void imprimirSolucion(std::vector<int> const& sol) {
	for (int j = 0; j < sol.size(); ++j) std::cout << sol[j] << " ";
	std::cout << "\n";
}

bool esValida(std::vector<int> sol, std::vector<std::string> listaJuguetes) {
	if (sol.size()% 2 == 0) { //Tenemos una solucion cuando tam de sol = 2, 4, 6, etc y 
		if (sol[sol.size() - 1] == sol[sol.size() - 2]) return false;
		else if (sol[sol.size() - 2] > sol[sol.size() - 1]) return false;
		else return true;
	}
	else return true;
	
}

bool resolver(std::vector<std::string> listaJuguetes, int numNinos, std::vector<int> &sol) {
	bool retorno = false;
	for (int i = 0; i < listaJuguetes.size(); ++i) {
		sol.push_back(i);
		if (esValida(sol, listaJuguetes)) {
			if (sol.size() == numNinos * 2) {
				imprimirSolucion(sol);
				return true;
			}
			else retorno = resolver(listaJuguetes, numNinos, sol) || retorno;
		}
		sol.pop_back();
	}
	return retorno;
}

bool resuelveCaso() {
	int numJuguetesFabricados, numNinos;
	std::cin >> numJuguetesFabricados >> numNinos;
	if (!std::cin) return false;
	std::vector<std::string> listaJuguetes(numJuguetesFabricados);
	std::vector<int> sol;
	for (int i = 0; i < numJuguetesFabricados; ++i) std::cin >> listaJuguetes[i];
	if (!resolver(listaJuguetes, numNinos, sol)) std::cout << "SIN SOLUCION" << std::endl;
	else std::cout << "\n";
	return true;
}

int main() {
#ifndef DOMJUDGE
std::ifstream in("datos.txt");
auto cinbuf = std::cin.rdbuf(in.rdbuf());;
#endif // !DOMJUDGE
while (resuelveCaso());
#ifndef DOMJUDGE
std::cin.rdbuf(cinbuf);
system("PAUSE");
#endif // !DOMJUDGE

}