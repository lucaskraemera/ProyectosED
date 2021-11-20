#include <string>
#include "Trie.h"

using namespace std;

class Predictor{
	private:
		Trie* t;
		void ordenarArr(vector<stringConFrecuencia>* scf);
		vector<stringConFrecuencia> priorizarPalabras(vector<stringConFrecuencia> *scfAux,vector<stringConFrecuencia> *scf,int k);
	public:
		Predictor();
		~Predictor();
		void insert(string s,int frecuencia);
		vector<string> busqueda(string aBuscar,int k);
};
