#include <iostream>
#include <fstream>
#include <vector>

struct tAdorno {
	int precio;
	int superficie;
};

void resolver(std::vector<tAdorno> const& adornos, int presupuesto, int precioActual, int superficieActual,  int &solMejor, std::vector<bool> &adornosComprados) {
	for (int i = 0; i < adornos.size(); ++i) {
		if (!adornosComprados[i]) {
			if (precioActual + adornos[i].precio <= presupuesto) {
				precioActual += adornos[i].precio;
				superficieActual += adornos[i].superficie;
				adornosComprados[i] = true;
				if (superficieActual>solMejor) solMejor = superficieActual;
				else resolver(adornos, presupuesto, precioActual, superficieActual, solMejor, adornosComprados);
				adornosComprados[i] = false;
				superficieActual -= adornos[i].superficie;
				precioActual -= adornos[i].precio;
			}
		}
	}

}

bool resuelveCaso() {
	int objetosAComprar, presupuesto;
	std::cin >> objetosAComprar >> presupuesto;
	if (!std::cin) return false;
	std::vector<tAdorno> adornos(objetosAComprar);
	std::vector<bool> adornosComprados(objetosAComprar, false);
	for (int i = 0; i < objetosAComprar; ++i) std::cin >> adornos[i].precio >> adornos[i].superficie;
	int solMejor = 0;
	resolver(adornos, presupuesto, 0, 0, solMejor, adornosComprados);
	std::cout << solMejor << std::endl;
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