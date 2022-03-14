#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct devolucion {
	int maximoGanados;
	int numVeces;
	int haceCuanto;
};

devolucion resolver(vector<int> const& resultados) {
	int contador = 0, valorMaximo = 0, numVeces = 0, haceCuanto = 0;
	for (int i = 0; i < resultados.size(); ++i) {
		if (resultados[i] <= 0) contador = 0; //Hemos perdido
		else ++contador; //Se suma contador porque victoria
		haceCuanto++;
		if (contador == valorMaximo && contador != 0) {
			numVeces++; //Si hemos igualado
			haceCuanto = 0;
		}
		else if (contador > valorMaximo) {
			numVeces = 1;
			valorMaximo = contador;
			haceCuanto = 0;
		}
	}
	devolucion retorno = {valorMaximo, numVeces, haceCuanto};
	return retorno;
}

bool resolverCaso() {
	int n;
	cin >> n;

	if (!std::cin)
		return false;
	else {
		vector<int> resultados(n);
		for (int& i : resultados) cin >> i;
		devolucion sol = resolver(resultados);
		cout << sol.maximoGanados << " " << sol.numVeces << " " << sol.haceCuanto << endl;
	}



	return true;
}

int main() {
#ifndef DOMJUDGE
	ifstream in("datos.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());
#endif // !DOMJUDGE
	while (resolverCaso());
#ifndef DOMJUDGE
	cin.rdbuf(cinbuf);
	system("PAUSE");
#endif // !DOMJUDGE
}