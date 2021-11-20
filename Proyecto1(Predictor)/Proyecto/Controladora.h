#include "Predictor.h"
#include <fstream>

class Controladora{
	private:
		void imprimirResultados(vector<string> resultados, string aBuscar);
		Predictor* pred;
		ifstream diccionario;
		ifstream archivoBusqueda;
		ofstream archivoSalida;
		int k;
	public: 
		Controladora(char* diccionario,char* archivoBusqueda, char* resultados,int ka);
		~Controladora();
		void lecturaDiccionario();
		void busqueda();
};
